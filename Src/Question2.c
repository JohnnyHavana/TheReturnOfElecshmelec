#include "Question2.h"

int zoomValue = 1;

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


void startPressed(){
	if(paused){
		paused = 0;
		buttons[0].pressed = 1;
		buttons[1].pressed = 0;
		osMutexWait(myMutex01Handle, osWaitForever);
		showButton(buttons[1]);
		showButton(buttons[0]);
		osMutexRelease(myMutex01Handle);

		osMutexRelease(PlayMutexHandle);

	}
}

void stopPressed(){
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
		loading = 1;
		loadData();
		system_safe_printf("Loading operation complete\n");
		loading = 0;
	}
	else
	{
		loading = 0;

	}
}

void savePressed(uint8_t saveNo)
{
	//todo evan come back to this section on monday
//	if(recording || loading){
//		return;
//	}
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

void zoomInPressed()
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


void zoomOutPressed()
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

void updateSpeed()
{
	if(zoomValue == 1)
	{
		speedValue = ZOOMSPEEDONE;
		updateTimeSpan("10s");
	}
	else if(zoomValue  == 2)
	{
		speedValue = ZOOMSPEEDTWO;
		updateTimeSpan("6s");

	}
	else if(zoomValue == 3)
	{
		speedValue = ZOOMSPEEDTHREE;
		updateTimeSpan("3s");

	}
	else
	{
		speedValue = ZOOMSPEEDFOUR;
		updateTimeSpan("1s");

	}

}

void updateTimeSpan(char* newTimeScale)
{
	  BSP_LCD_DisplayStringAt(240, 172, newTimeScale, LEFT_MODE);
}
