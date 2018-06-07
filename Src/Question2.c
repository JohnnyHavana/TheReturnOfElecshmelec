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



}

void savePressed(uint8_t saveNo){
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







