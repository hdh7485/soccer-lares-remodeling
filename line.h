#include "ultra.h"
#include "light.h"
#include "motor.h"

unsigned char Escape_Dir[15] = {   10 // 경계라인 감지 안됨
                                 , 4 // 0(전) 감지 - 4(후)로 탈출
                                 , 6 // 1(우) 감지 - 6(좌)로 탈출
                                 , 0 // 2(후) 감지 - 0(전)로 탈출
                                 , 2 // 3(좌) 감지 - 2(우)로 탈출
                                 , 5 // 0, 1(전, 우) 감지 - 6(후, 좌)로 탈출
                                 , 3 // 0, 3(전, 좌) 감지 - 3(후, 우)로 탈출
                                 , 7 // 2, 1(후, 우) 감지 - 7(전, 좌)로 탈출
                                 , 1 // 2, 3(후, 좌) 감지 - 1(전, 우)로 탈출
                                 , 6 // 0, 1, 2(전, 우, 후) 감지 - 6(좌)로 탈출
                                 , 0 // 1, 2, 3(우, 후, 좌) 감지 - 0(전)로 탈출
                                 , 2 // 3, 0, 1(후, 좌, 전) 감지 - 2(우)로 탈출
                                 , 4 // 3, 0, 1(좌, 전, 우) 감지 - 4(후)로 탈출
                                 , 11 // 0, 2(전, 후) 감지 - 
                                 , 12 // 1, 3(우, 좌) 감지 - 
                               };



find_line(){
  /*if(light[0] >= )
  {
    
  }
  light[1];
  light[2];
  light[3];*/
}

void UL(int d)
{
  if(ultra[0] <= d)
  {
    dir_move(6, 100);
  }
  else if(ultra[1] <= d)
  {
    dir_move(9, 100);
  }
  else if(ultra[2] <= d)
  {
    dir_move(0, 100);
  }
  else if(ultra[3] <= d)
  {
    dir_move(3, 100);
  }
  //4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
  else if(ultra[0] <= d && ultra[1] <= d)
  {
    dir_move(7, 100);
  }
  else if(ultra[0] <= d && ultra[2] <= d)
  {
    if(ultra[1] < ultra[3])
    {
      dir_move(9, 100);
    }
    else
    {
      dir_move(3, 100);
    }
  }
  else if(ultra[0] <= d && ultra[3] <= d)
  {
    dir_move(5, 100);
  }
  else if(ultra[1] <= d && ultra[2] <= d)
  {
    dir_move(11, 00);
  }
  else if(ultra[1] <= d && ultra[3] <= d)
  {
    if(ultra[0] < ultra[2])
    {
      dir_move(6, 100);
    }
    else
    {
      dir_move(0, 100);
    }
  }
  else if(ultra[2] <= d && ultra[3] <= d)
  {
    dir_move(1, 0);
  }
//66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
  else if(ultra[0] <= d && ultra[1] <= d && ultra[2] <= d)
  {
    dir_move(9, 100);
  }
  else if(ultra[1] <= d && ultra[2] <= d && ultra[3] <= d)
  {
    dir_move(0, 100);
  }
  else if(ultra[2] <= d && ultra[3] <= d && ultra[0] <= d)
  {
    dir_move(3, 100);
  }
  else if(ultra[3] <= d && ultra[0] <= d && ultra[1] <= d)
  {
    dir_move(6, 100);
  }
//44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
  else if(ultra[0] <= d && ultra[1] <= d && ultra[2] <= d && ultra[3] <= d)
  {
    dir_move(0, 0);
  }
}

void line_detected(int line){
  if(line == 10)
  {
    
  }
  else if(line == 11)
  {
    UL(40);
  }
  else if(line == 12)
  {
    UL(40);
  }
  else
  {
    //dir_move(Escape_Dir[light]);
  }
}

