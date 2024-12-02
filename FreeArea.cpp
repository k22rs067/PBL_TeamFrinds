#include "FreeArea.h"
//#include "BluetoothLogger.h"
// #include <ctime>
#include <stdio.h>

#define CALIB_FONT_HEIGHT (16 /*TODO: magic number*/)


FreeArea::FreeArea(FreeAreaTactics *FreeAreaTactics)
: mFreeAreaTactics(FreeAreaTactics)
{
	state = 0; //<-スタート位置から
}

FreeArea::~FreeArea()
{
}

/**
* 区間制御戦術を実行する
*/
void FreeArea::execute()
{
    switch (state)
    {
        case 0:
            //ライントレース初期設定
            mFreeAreaTactics->LineTrace(BLUE);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 10;
            }
	    break;

        case 10:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 20;
           }
        break;

        case 20: 
            mFreeAreaTactics->Turn_Right();
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 30;
            }
        break;

        case 30:
            mFreeAreaTactics->LineTrace(BLUE);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 50;
            }
	    break;

        case 50:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 60;
           }
        break;

        case 60:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 70;
            }
        break;

        case 70:
            //ライントレース初期設定
            mFreeAreaTactics->LineTrace(RED);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 80;
            }
	    break;

        case 80:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 90;
           }
        break;

        case 90:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 100;
            }
        break;

        case 100:
            mFreeAreaTactics->LineTrace(RED);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 110;
            }
	    break;

        case 110:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 120;
           }
        break;

        case 120:
            mFreeAreaTactics->Turn_Left();
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 130;
            }
        break;

        case 130:
            mFreeAreaTactics->LineTrace(RED);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 140;
            }
	    break;

        case 140:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 150;
           }
        break;

        case 150:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 160;
            }
        break;

        case 160:
            //ライントレース初期設定
            mFreeAreaTactics->LineTrace(YELLOW);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 170;
            }
	    break;

        case 170:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 180;
           }
        break;

        case 180:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 190;
            }
        break;

        case 190:
            mFreeAreaTactics->LineTrace(YELLOW);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 200;
            }
	    break;

        case 200:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 210;
           }
        break;

        case 210:
            mFreeAreaTactics->Turn_Left();
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 220;
            }
        break;

        case 220:
            mFreeAreaTactics->LineTrace(YELLOW);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 230;
            }
	    break;

        case 230:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 240;
           }
        break;

        case 240:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 250;
            }
        break;

        case 250:
            //ライントレース初期設定
            mFreeAreaTactics->LineTrace(GREEN);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 260;
            }
	    break;

        case 260:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 270;
           }
        break;

        case 270:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 280;
            }
        break;

        case 280:
            mFreeAreaTactics->LineTrace(YELLOW);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 290;
            }
	    break;

        case 290:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 300;
           }
        break;

        case 300:
            mFreeAreaTactics->Turn_Left();
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 310;
            }
        break;

        case 310:
            mFreeAreaTactics->LineTrace(GREEN);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 320;
            }
	    break;

        case 320:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 330;
           }
        break;

        case 330:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 340;
            }
        break;

        case 340:
            //ライントレース初期設定
            mFreeAreaTactics->LineTrace(BLUE);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 350;
            }
	    break;

        case 350:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 360;
           }
        break;

        case 360:
            mFreeAreaTactics->CircleStraight();
            if(mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 370;
            }
        break;

        case 370:
            mFreeAreaTactics->LineTrace(BLUE);
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 380;
            }
	    break;

        case 380:
           mFreeAreaTactics->ArmControl();
           if (mFreeAreaTactics->isFinished())
           {
                mFreeAreaTactics->setFlag(false);
                state = 390;
           }
        break;

        case 390:
            mFreeAreaTactics->Turn_Left();
            if (mFreeAreaTactics->isFinished())
            {
                mFreeAreaTactics->setFlag(false);
                state = 30;
            }
        break;
/*
        case 70:
           //青サークル2まで
            mLineTraceAction->start();
            if(mEV3ColorSensor->isColor_BLUE())//mDistanceJudgement->isDistanceOut()
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=80;
            }
        break;

        case 80:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 90;
            }
        break;

        case 90:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 100;
            }
        break;

        case 100: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 110;
            }
        break;

        case 110:
           //赤サークル1まで
            mLineTraceAction->start();
            if(mEV3ColorSensor->isColor_RED())//mDistanceJudgement->isDistanceOut()
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=120;
                //state = 2500;

            }
        break;

        case 120:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 130;
            }
        break;

        case 130:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 140;
            }
        break;

        case 140: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 150;
            }
        break;

        case 150:
           //赤サークル2まで
            mLineTraceAction->start();
            if(mEV3ColorSensor->isColor_RED())//mDistanceJudgement->isDistanceOut()
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=160;
            }
        break;

        case 160:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 170;
            }
        break;

        case 170:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0 )
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state = 180;
            }
        break;

        case 180: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(-90);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 190;
            }
        break;

        case 190:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state=200;
            }
        break;

        case 200:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=210;
            }
        break;

        case 210:
           //赤サークル3まで
            mLineTraceAction->start();
            if(mEV3ColorSensor->isColor_RED())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=220;
                //state = 2500;
            }
        break;

        case 220:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 230;
            }
        break;

        case 230:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 240;
            }
        break;

        case 240: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 250;
            }
        break;

        case 250:
           //黄サークル1まで
            mLineTraceAction->start();
            if(mEV3ColorSensor->isColor_YELLOW())//mDistanceJudgement->isDistanceOut()
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
		        state=260;
            }
        break;

        case 260:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 270;
            }
        break;

        case 270:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 280;
            }
        break;

        case 280: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 290;
            }
        break;

        case 290:
           //黄サークル2まで
            mLineTraceAction->start();
            if(mEV3ColorSensor->isColor_YELLOW())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                /*
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                */
               /*
		        state=300;
                //state = 1000; //GOAL2へ
            }
        break;
        case 300:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 310;
            }
        break;

        case 310:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state = 320;
            }
        break;

        case 320: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(-90);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 330;
            }
        break;

        case 330:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state=340;
            }
        break;

        case 340:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=350;
            }
        break;

        case 350:
           //黄サークル3まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=360;
            }
        break;

        case 360:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 370;
            }
        break;

        case 370:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 380;
            }
        break;

        case 380: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 390;
            }
        break;

        case 390:
           //緑サークル1まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=400;
            }
        break;

        case 400:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 410;
            }
        break;

        case 410:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 420;
            }
        break;

        case 420: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 430;
            }
        break;

        case 430:
           //緑サークル2まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=440;
            }
        break;

        case 440:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 450;
            }
        break;

        case 450:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state = 460;
            }
        break;

        case 460: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(-90);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 470;
            }
        break;

        case 470:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state=480;
            }
        break;

        case 480:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=490;
            }
        break;

        case 490:
           //緑サークル3まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state=500;
            }
        break;

        case 500:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        //mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 510;
            }
        break;

        case 510:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() <= 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 520;
            }
        break;

        case 520: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 530;
            }
        break;

        case 530:
           //青サークル1まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
		        //state=540;
                state = 560;
            }
        break;

        case 540:
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 540;
            }
        break;

        case 550:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 560;
                //state = 2000; //GOAL2まで時計回りで走行
            }
        break;

        case 560: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 570;
            }
        break;

        case 570:
           //青サークル2まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
		        state = 580; //サークルループ
                //state = 2500 //動作終了
            }
        break;

        case 580:
            //サークルループ
            mArmControl->setPower(10);
            if (mArmControl->getEncoder() >= armAngle)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                state = 590;
            }
        break;

        case 590:
            mArmControl->setPower(-10);
            if (mArmControl->getEncoder() == 0)
            {
		        mArmControl->setPower(0);	//アーム停止
		        mArmControl->setBrake(true);
		        //mArmControl->resetEncoder();	//エンコーダ値をリセット
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state = 600;
            }
        break;

        case 600: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(-90);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 610;
            }
        break;

        case 610:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state=620;
            }
        break;

        case 620:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=70;
            }
        break;


        case 1000: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(90);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 1010;
            }
        break;

        case 1010:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state=1020;
            }
        break;

        case 1020:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=2500;
            }
        break;

        case 2000: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(180);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 2010;
            }
        break;

        case 2010:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state=2020;
            }
        break;

        case 2020:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=2030;
            }
        break;

        case 2030:
           //緑サークル3まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
                state = 2040;
            }
        break;

        case 2040: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 2050;
            }
        break;

        case 2050:
           //緑サークル2まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
		        state=2060;
            }
        break;

        case 2060: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mLineTraceAction->stop(); 
                mDistanceJudgement->stop();
		        mCalcCurrentLocation->setAngle(0);
                mRunParameter->setRotateAngle(90);
                mRunParameter->setRotateSpeed(15);
                mRotateMachineAction->updateParameter();
		        state = 2070;
            }
        break;

        case 2070:
            mRotateMachineAction->start();
            if(mRotateMachineAction->isFinished())
            {
                mRotateMachineAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(rotateDistance);
                mDistanceJudgement->start();
                state=2080;
            }
        break;

        case 2080:
            mRunStraightAction->straight(10,10);
            if(mDistanceJudgement->isDistanceOut())
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state=2090;
            }
        break;

        case 2090:
           //緑サークル1まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
		        state = 2100;
            }
        break;

        case 2100: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 2110;
            }
        break;

        case 2110:
           //黄サークル3まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
		        state=2120;
            }
        break;

        case 2120: 
            //直進
            mRunStraightAction->straight(10,10);
            if (mDistanceJudgement->isDistanceOut())////gEV3ColorSensor->isColor_BLUE()
            {
                mRunStraightAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(lineDistance);
                mDistanceJudgement->start();
		        state = 2130;
            }
        break;

        case 2130:
           //黄サークル2まで
            mLineTraceAction->start();
            if(mDistanceJudgement->isDistanceOut())
            {
                mLineTraceAction->stop();
                mDistanceJudgement->stop();
                mDistanceJudgement->setDistance(straightDistance);
                mDistanceJudgement->start();
		        state=2500;
            }
        break;

	case 2500://動作完了用
		mLineTraceAction->stop();
		flag = true;
		break;
	default:
		break;
	}
}
*/
    }
}

bool FreeArea::isFinished()
{
	return flag;
}
