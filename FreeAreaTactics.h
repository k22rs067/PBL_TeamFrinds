#ifndef FREE_AREA_TACTICS_H
#define FREE_AREA_TACTICS_H

#include "Tactics.h"
#include "RearMotor.h"

class FreeAreaTactics : public Tactics
{
public:
  explicit FreeAreaTactics();
  virtual ~FreeAreaTactics();

  void execute(); //戦術を実行する
  bool isFinished();

  void stop();
  void LineTrace_count(int color);
  void LineTrace2(int color);
  void LineTrace_Jugde_P(int color);
  void LineTrace_Jugde_O(int color);
  void ArmControl();
  void Straight_Back();
  void Turn_Right();
  void Turn_Right2();
  void Turn_Left();
  void Turn_Left2();
  void Uturn();
  void CircleStraight();
  void Straight();
  void obstacle(int color);
  void present(int color);
  void setFlag(bool setflag);
  void setPresent(int p);
  void setObstacle(int o);
  void setColor(int color);
  int getPresent(int p);
  int getObstacle();
  int getColor(int color);
  bool ObjectDetection(int object);


private:
  /* パラメータ指定用の添字 */
  double target = 38.5;
  double rotateDistance = 9;     //旋回前後のstraightの距離
  double straightDistance = 15;   //旋回以外のstraightの距離
  double lineDistance = 25;       //サークル間の距離
  double backDistance = -10;       //後退距離
  double armAngle = 65;//50
  const int SPEED = 0;
  const int KP = 1;
  const int KI = 2;
  const int KD = 3;
  double retentionAngle[2];
  bool flag = false;
  bool Flag = false;
  bool Oflag = false;
  bool Pflag = false;
  //あまり触らない
  const int offset1 = 8; //6 8
  const int offset2 = 8;
  const int angle1 = 90;
  const int angle2 = 53; //53

  const int BLUE = 0;
  const int RED = 1;
  const int GREEN = 2;
  const int YELLOW = 3;

  double section4[4] = {12, 0.02, 0, 1};  //格子状

  int state = 0;
  int state_line = 0;
  int state_line2 = 0;
  int state_right = 0;
  int state_left = 0;
  int state_left2 = 0;
  int state_Uturn = 0;
  int state_straight = 0;
  int state_cstraight = 0;
  int state_obstacle = 0;
  int state_present = 0;
  int state_object = 0;
  int state_back = 0;

  
  int blue_count = 0;
  int red_count = 0;
  int green_count = 0;
  int yellow_count = 0;
  int color_count = 0;

  int Present = 0;
  int p_count = 0;
  int result_p = 0;
  int o_count = 0;

  int i = 0;

};


#endif