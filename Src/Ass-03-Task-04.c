/**
 * ELEC3730 ASSIGNMENT 3
 * TASK 4 - ADC Values
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class handles all the input and outputs for the graph in the pulse rate monitor
 *
 * */
#include "Ass-03.h"
#include "Question1.h"
#include "Question2.h"

// This is the task that reads the analog input. A buffer is divided in two to
// allow working on one half of the buffer while the other half is being
// loaded using the DMA controller.
//
// This task also plots the wave form to the screen.
//
// *** MAKE UPDATES TO THE CODE AS REQUIRED ***
//
// Note that there needs to be a way of starting and stopping the display.

uint16_t ADC_Value[1000];
void recordData(int data);
void loadData();


speedValue = 500;

/*
 * One of the four entry points to the program.
 * Gets value from the HAL and puts it in an array of values
 * We can control the speed value to determine the period of the time span
 * This also affects the smoothness of the curves
 * */
void Ass_03_Task_04(void const * argument)
{
  uint16_t i;
  HAL_StatusTypeDef status;
  uint16_t xpos=0;
  uint16_t ypos=0;
  uint16_t last_xpos=0;
  uint16_t last_ypos=0;
#define XOFF 10
#define YOFF 10
#define XSIZE 240
#define YSIZE 160



  osSignalWait(1,osWaitForever);
  system_safe_printf("Hello from Task 4 - Analog Input (turn ADC knob or use pulse sensor)\n");
  // Draw a box to plot in
  osMutexWait(myMutex01Handle, osWaitForever);
  BSP_LCD_DrawRect(XOFF-1,YOFF-1,XSIZE+1,YSIZE+1);
  osMutexRelease(myMutex01Handle);
  // Start the conversion process
  status = HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&ADC_Value, 1000);
  if (status != HAL_OK)
  {
	  error_safe_printf("Task 4 HAL_ADC_Start_DMA() %d\n", status);
  }

  // Start main loop
  while (1)
  {
	  // Wait for first half of buffer

	  osSemaphoreWait(myBinarySem05Handle, osWaitForever);
	  //wait until the screen is unpaused
//	  osMutexWait(showButtonMutexHandle, osWaitForever);
	  osMutexWait(PlayMutexHandle, osWaitForever);
	  osMutexWait(myMutex01Handle, osWaitForever);
	  if(!loading)
	  {

		  for(i=0;i<500;i=i+speedValue) //upadated for zoom function
		  {
			  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			  BSP_LCD_DrawVLine(XOFF+xpos,YOFF,YSIZE);
			  if(record){
				  BSP_LCD_SetTextColor(LCD_COLOR_RED);
			  }else{
				  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			  }
			  ypos=(uint16_t)((uint32_t)(ADC_Value[i])*YSIZE/4096);
			  BSP_LCD_DrawLine(XOFF+last_xpos,YOFF+last_ypos,XOFF+xpos,YOFF+ypos);
			  // BSP_LCD_FillRect(xpos,ypos,1,1);
			  last_xpos=xpos;
			  last_ypos=ypos;

			  xpos++;
			  if(record){
				  recordData(ypos);
			  }

			  if(isAnaloging)
			  {
				  if(analogTimer > 0){
					  analogTimer -= ((float)speedValue/50.0) / 240 *1000;
				  }else{
					  //turn analog off
					  analogChange =1;

					  i= 500;
				  }
			  }

			  //
			  //10seconds/240

		  }
	  }else{

		  if(loadingBufferNo > bufferEnd){
			  osMutexRelease(myMutex01Handle);
			  loadPressed();
			  osMutexWait(myMutex01Handle, osWaitForever);
		  }
		  if(loading){//loading could change if reached end of thingo
			  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			  BSP_LCD_DrawVLine(XOFF+xpos,YOFF,YSIZE);
			  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);

			  ypos = loadingBuffer[loadingBufferNo];
			  loadingBufferNo ++;
			  BSP_LCD_DrawLine(XOFF+last_xpos,YOFF+last_ypos,XOFF+xpos,YOFF+ypos);
			  last_xpos=xpos;
			  last_ypos=ypos;
			  xpos++;
		  }

	  }
	  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	  osMutexRelease(myMutex01Handle);
	  osMutexRelease(PlayMutexHandle);
//	  osMutexRelease(showButtonMutexHandle);

	  if(analogChange){
		  isAnaloging =0; //todo evan you were here
		  analogTimer =0;
		  stopPressed();
//		  osMutexWait(PlayMutexHandle, osWaitForever);
//		  paused =1;
		  analogChange =0;
	  }

	  if (last_xpos>=XSIZE-1)
	  {
		  xpos=0;
		  last_xpos=0;
	  }

	  // Wait for second half of buffer
	  osSemaphoreWait(myBinarySem06Handle, osWaitForever);
//	  osMutexWait(showButtonMutexHandle, osWaitForever);
	  osMutexWait(PlayMutexHandle, osWaitForever);



	  HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_SET);
	  osMutexWait(myMutex01Handle, osWaitForever);
	  if(!loading)
	  {
		  for(i=0;i<500;i=i+speedValue)
		  {
			  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			  BSP_LCD_DrawVLine(XOFF+xpos,YOFF,YSIZE);
			  if(record){
				  BSP_LCD_SetTextColor(LCD_COLOR_RED);
			  }else{
				  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			  }
			  ypos=(uint16_t)((uint32_t)(ADC_Value[i])*YSIZE/4096);
			  BSP_LCD_DrawLine(XOFF+last_xpos,YOFF+last_ypos,XOFF+xpos,YOFF+ypos);
			  // BSP_LCD_FillRect(xpos,ypos,1,1);
			  last_xpos=xpos;
			  last_ypos=ypos;

			  xpos++;
			  if(record){
				  recordData(ypos);
			  }
			  if(isAnaloging)
			  {
				  if(analogTimer > 0){
					  analogTimer -= ((float)speedValue/50.0) / 240.0 * 1000.0 ;
				  }else{
					  //turn analog off
					  analogChange =1;
					  i=500;
				  }
			  }
		  }

	  }else{

		  if(loadingBufferNo > bufferEnd){
			  osMutexRelease(myMutex01Handle);
			  loadPressed();
			  osMutexWait(myMutex01Handle, osWaitForever);


		  }else{//loading could change if reached end of thingo
			  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			  BSP_LCD_DrawVLine(XOFF+xpos,YOFF,YSIZE);
			  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
			  ypos = loadingBuffer[loadingBufferNo];
			  loadingBufferNo ++;
			  BSP_LCD_DrawLine(XOFF+last_xpos,YOFF+last_ypos,XOFF+xpos,YOFF+ypos);
			  last_xpos=xpos;
			  last_ypos=ypos;
			  xpos++;
		  }

	  }
	  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	  osMutexRelease(myMutex01Handle);

	  if (last_xpos>=XSIZE-1)
	  {
		  xpos=0;
		  last_xpos=0;
	  }
	  osMutexRelease(PlayMutexHandle);

	  HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_RESET);

	  if(analogChange){
		  isAnaloging =0;
		  analogTimer =0;
//
//		  osMutexWait(PlayMutexHandle, osWaitForever);
//		  paused =0;
		  stopPressed();
		  analogChange =0;
	  }
//	  osMutexRelease(showButtonMutexHandle);
  }
}

// STEPIEN: Add callback functions to see if this can be used for double buffering equivalent


/*
 * Releases binary semaphore for ADC
 * */
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	osSemaphoreRelease(myBinarySem05Handle);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	HAL_GPIO_WritePin(GPIOD, LD3_Pin, GPIO_PIN_SET);
	osSemaphoreRelease(myBinarySem06Handle);
	HAL_GPIO_WritePin(GPIOD, LD3_Pin, GPIO_PIN_RESET);
}


/*
 * Loads data from csv file
 * We are reading char by char and determining where the commas are to separate the numbers
 * This reduces stress on the CPU rather than creating an array of 50000 and running through that
 *
 * */
void loadData()
{
	loadingBufferNo =0;
	char filePathPlusSource[256];

	strcpy(filePathPlusSource, currentFilePath);
	strcat(filePathPlusSource, "/");
	strcat(filePathPlusSource, "sav");
	char num[1];
	sprintf(num,"%d", globalSaveNo);
	strcat(filePathPlusSource, num);
	strcat(filePathPlusSource, ".csv");

	FIL file;
	#define BUFF_SIZE 1
	FRESULT res;
	uint32_t bytesread;



	//make sure the file actually exists
	int fileExistenceCheck = checkFileFolderExists(filePathPlusSource);
	if(fileExistenceCheck != 1) //if doesnt exist
	{
		error_safe_printf("The File does not exist\n");
		return;
	}

	// Open the file
	if((res = f_open(&file, filePathPlusSource, FA_READ)) != FR_OK)
	{
		error_safe_printf("Opening '%s'\n", filePathPlusSource); //if we had an issue with opening
		return;
	}

	uint32_t totalBytesRead = 0; //used for determining EOF. probably couldve used f_eof() instead

	system_safe_printf("Opened file '%s'\n", filePathPlusSource);
	// Read data from file


	FSIZE_t fileSize = f_size(&file); //get file size
	debug_safe_printf("File Size of File is: %d bytes\n",(int)fileSize);

	//now we can start to look through the file char by char
	char tempString[4];
	uint8_t tempStringIndex = 0;
	char tempInput[10];
	char currentChar;
	char previousChar = ' ';

	int xAxisPlot = 0;



	while(totalBytesRead < fileSize) //whilst we arent at the end
	{
		//reading one byte at a time for each char in the string
		res = f_read(&file, tempInput, BUFF_SIZE, &bytesread);

		if (res != FR_OK) //if somehow fail
		{
			error_safe_printf("Function did not succeed. Current File Path: '%s'\n", filePathPlusSource);
			f_close(&file);
			return;
		}
		else //all is good
		{
			currentChar = tempInput[0]; //get the char from the temp string, since we are only read one at a time
			//input_safe_printf("I have read =>%c\n", currentChar);

			if(previousChar == ',' && currentChar == ' ') //used for csv files(or at least ours)
			{
				//comma and  space
				//so the number is finished
				tempString[tempStringIndex] = 0; //cap with null terminator
				//string finished
				//input_safe_printf("Current tempstring is: %s\n", tempString);
//				input_safe_printf("X: %d, Y: %d\n", xAxisPlot, atoi(tempString));
				loadingBuffer[xAxisPlot] = (uint8_t)atoi(tempString);

				//reset temp string index
				tempStringIndex = 0;
				//reset temp string
				for(int i = 0; i < 4;i++)
				{
					tempString[i] = 0;
				}
				//update x axis
				xAxisPlot++;


			}
			else
			{
				//valid number
				if(currentChar != ',')
				{
					tempString[tempStringIndex] = currentChar; //add to our good char array
					tempStringIndex++; //increment index for next go round
				}
			}

			previousChar = currentChar;


			totalBytesRead += bytesread;

		}
	}

	//finished reading file
	//loadingBuffer[bytesread] = '\0';

	// Close file
	f_close(&file);
	bufferEnd = xAxisPlot;
	for(int i = 0 ; i<= bufferEnd; i++){ //print out values we found from file
		input_safe_printf("X: %d, Y: %d\n", i, loadingBuffer[i]);
	}
	input_safe_printf("Buffer End %d\n", bufferEnd);


}



/*
 * Method is called a maximum 10000 times whilst recording
 * Adds value to an array ready for writing to file
 * */
void recordData(int data)
{
	//method is called 10000 times for each data point that is recorded

	//statics are used for maintaining positions throughout each method call
	static int currentArrayPos =0; //start at 0, eventually get to 10000
	static int maxSize = 10000;
	static uint8_t dataValues[10000];

	//stop recording once the current array position hits 10000
	if(currentArrayPos == maxSize)
	{
		stopRecording = 1;
	}
	else
	{
		//keep adding to the data value array
		dataValues[currentArrayPos] = data;
	}

	if(stopRecording)
	{
		//save data in one of the data things
		//then we need to wait until another button is pressed

		system_safe_printf("Recording completed\n");
		//safe_printf("%s\n", "here");


		//build filePathPlusSource - to store to position of save file.
		char filePathPlusSource[256];
		for(int i = 0; i < 256;i++)
		{
			filePathPlusSource[i] = 0;
		}
		strcat(filePathPlusSource, currentFilePath);
		strcat(filePathPlusSource, "/");
		strcat(filePathPlusSource, "sav");
		char num[1];
		sprintf(num,"%d", globalSaveNo);
		strcat(filePathPlusSource, num);
		strcat(filePathPlusSource, ".csv");

		if(debugOn == 1){debug_safe_printf("FilePathPlus Source for Saving is =>%s\n",filePathPlusSource);}

		//Determine if the file path plus the source already exists on the Sd card
		//If file already exists, remove the current file and create a new file
		if(checkFileFolderExists(filePathPlusSource) ==1)
		{
//			safe_printf("In 1 %s\n", filePathPlusSource);
			rm2(filePathPlusSource);
		}
		if(checkFileFolderExists(filePathPlusSource) ==2)
		{
			//file doesnt exist, make the file
//			safe_printf("In 2 %s\n", filePathPlusSource);
			mkfilForRecording(filePathPlusSource);//make the file
		}
		else
		{
			//Should not be reached, file can either exist or not
			return;
		}



		//now we can start writing all values to the file
		//If we are at this position, the current array position must be at 10000

		//for each element that we have in the dataValues array, we want to write that to the file

		for(int i = 0; i < currentArrayPos;i++)
		{
			char valueToString[10];
			sprintf(valueToString, "%d", dataValues[i]);

			write2(filePathPlusSource, valueToString); //write2 will add a \n to each line

		}


		//reset everything now that everything is written to a file
		record = 0;
		stopRecording = 0;
		//reset all elements in the dataValues[] array
		for(int i = 0; i < 10000; i++)
			dataValues[i] = 0;

		//reset current array position
		currentArrayPos = 0;

		//finished.

	}
	else
	{
		//still recording, update current array pos
		currentArrayPos ++;
	}

}





