#include "Question2.h"

/*
 *
 * ELEC3730 ASSIGNMENT 3
 * QUESTION2.H
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class stores relevant methods that are used to build functionality for question 2
 *
 * */





int zoomValue = 1;

/*
 * Takes in a button and determines the id
 * Uses a switch case to call an appropriate function based on its id
 * */
void buttonPressed(Button buttonNutton){
	switch(buttonNutton.id){
	case(1):
		startPressed();
		break;
	case(2):
		stopPressed();
		break;
	case(3):
		loadPressed();
		break;
	case(4):
		recordPressed();
		break;
	case(5):
		savePressed(1);
		break;
	case(6):
		savePressed(2);
		break;
	case(7):
		savePressed(3);
		break;
	case(8):
		zoomInPressed();
		break;
	case(9):
		zoomOutPressed();
		break;
	}
}

/*
 *
 * */
void startPressed(){
	if(paused){
		paused = 0;
		buttons[0].pressed = 1;
		buttons[1].pressed = 0;
		//todo evan you were here
		//system_safe_printf("starting completed1\n");

		osMutexWait(myMutex01Handle, osWaitForever);
		//system_safe_printf("starting completed2\n");

		showButton(buttons[1]);
		//system_safe_printf("starting completed3\n");

		showButton(buttons[0]);
		//system_safe_printf("starting completed4\n");

		osMutexWait(myMutex01Handle, 0);

		osMutexRelease(myMutex01Handle);
		//system_safe_printf("starting completed5\n");

		osMutexRelease(PlayMutexHandle);
		//system_safe_printf("starting completed6\n");

	}
}

void stopPressed()
{
	if(!paused){
		paused = 1;
		buttons[1].pressed = 1;
		buttons[0].pressed = 0;
		osMutexWait(myMutex01Handle, osWaitForever);
		showButton(buttons[1]);
		showButton(buttons[0]);

		osMutexRelease(myMutex01Handle);
		osMutexWait(PlayMutexHandle, osWaitForever);
	}
}

void recordPressed(){
	if(record){
		stopRecording =1;
		buttons[3].pressed =0;
		system_safe_printf("Recording completed\n");

	}else{
		record = 1;
		stopRecording = 0;
		buttons[3].pressed =1;
	}

	osMutexWait(myMutex01Handle, osWaitForever);
	showButton(buttons[3]);
	osMutexRelease(myMutex01Handle);

}


void loadPressed(){


	if(!loading)
	{
		buttons[2].pressed = 1;

		loadData();
		system_safe_printf("Loading operation complete\n");
		loading = 1;
	}
	else
	{
		loading = 0;
		buttons[2].pressed = 0;
		bufferEnd =0;
		loadingBufferNo =0;
	}

	osMutexWait(myMutex01Handle, osWaitForever);
	showButton(buttons[2]);
	osMutexRelease(myMutex01Handle);
}

void savePressed(uint8_t saveNo)
{
	//if recording or loading do not change the save file
	if(record || loading){
		return;
	}
	//release mutex shit
	globalSaveNo = saveNo;

	buttons[6].pressed = 0;
	buttons[5].pressed = 0;
	buttons[4].pressed = 0;
	buttons[3+saveNo].pressed =1;

	osMutexWait(myMutex01Handle, osWaitForever);
	showButton(buttons[6]);
	showButton(buttons[5]);
	showButton(buttons[4]);
	osMutexRelease(myMutex01Handle);

}


/*
 * Increments the zoom value if allowed, updates speed value as well
 * */
void zoomInPressed()
{
	if(!record)
	{
		if(zoomValue == 1 || zoomValue == 2 || zoomValue == 3)
		{
			zoomValue++;
			updateSpeed();
		}
		else
		{
			error_safe_printf("Cannot zoom in further\n");
		}
	}


}

/*
 * Decrements zoom value if allowed, updates speed value as well
 * */
void zoomOutPressed()
{
	if(!record)
	{
		if(zoomValue == 2 || zoomValue == 3 || zoomValue == 4)
		{
			zoomValue--;
			updateSpeed();
		}
		else
		{
			error_safe_printf("Cannot zoom out further\n");
		}
	}
}

/*
 *Updates the speed value depending on the current zoom
 *Updates Updates the time span of the x axis
 * */
void updateSpeed()
{
	if(zoomValue == 1)
	{
		speedValue = ZOOMSPEEDONE; //speed set to 500
		updateTimeSpan("10s");
	}
	else if(zoomValue  == 2)
	{
		speedValue = ZOOMSPEEDTWO; //speed set to 250
		updateTimeSpan("6s");

	}
	else if(zoomValue == 3)
	{
		speedValue = ZOOMSPEEDTHREE; //speed set to 100
		updateTimeSpan("3s");

	}
	else
	{
		speedValue = ZOOMSPEEDFOUR; //speed set to 50
		updateTimeSpan("1s");

	}

}

/*
 * Updates time span label on the x axis
 * */
void updateTimeSpan(char* newTimeScale)
{
    BSP_LCD_SetFont(&Font8);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(235,172,15,7);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

    BSP_LCD_DisplayStringAt(235, 172, newTimeScale, LEFT_MODE);
}
