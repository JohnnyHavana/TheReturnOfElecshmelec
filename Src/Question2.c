#include "Question2.h"


void buttonPressed(Button buttonNutton){
	switch(buttonNutton.id){
	case(1):
		startPressed();
		break;
	case(2):
		stopPressed();
		break;
	case(3):
		recordPressed();
		break;
	case(4):
		loadPressed();
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
	}else{
		record = 1;
		stopRecording = 0;
	}
}


void loadPressed(){



}

void savePressed(uint8_t saveNo){
	if(stopRecording){
		//release mutex shit
		globalSaveNo = saveNo;

	}



}







