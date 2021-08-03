//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

  int x = -8, y = -8;
  int to_win = 10;
  bool strike(TImage * ball, TImage * brick){
    if(ball -> Left >= brick -> Left - ball -> Width &&
       ball -> Left <= brick -> Left + ball -> Width &&
       ball -> Top >= brick -> Top - ball -> Height &&
       ball -> Top <= brick -> Top + brick -> Height) {
        return true;
    } else return false;
 }

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerballTimer(TObject *Sender)
{
  ball->Left += x;
  ball->Top += y;

  // bounce left wall
  if(ball -> Left - 5 <= background -> Left) x = -x;

  //bounce top
  if(ball -> Top - 8 <= background -> Top) y = -y;

   //bounce right wall
  if(ball -> Left + ball -> Width + 5 >= background -> Width) x = -x;

  // lose the game
  if(ball -> Top >= paddle -> Top + paddle -> Height + 15){
     timerball -> Enabled = false;
     ball -> Visible = false;
     Button1 -> Caption = "You lost! Wanna play again?";
     Button1 -> Visible = true;

  } else if (ball -> Left > paddle -> Left - ball -> Width / 2 &&  ball -> Left < Left + paddle -> Width && ball -> Top + ball -> Height > paddle -> Top)
     {
         if(y > 0) y = -y;
     }

   // win
   if(to_win <= 0){
     timerball -> Enabled = false;
     ball -> Visible = false;
     Button1 -> Caption = "You won! Wanna play again?";
     Button1 -> Visible = true;
   
   }

   // block 1
   if(strike(ball, Image1) && Image1 -> Visible == true)
   {x = -x; y = -y; Image1 -> Visible = false; to_win--;}

   // block 2
   if(strike(ball, Image2) && Image2 -> Visible == true)
   {x = -x; y = -y; Image2 -> Visible = false; to_win--;}

   // block 3
   if(strike(ball, Image3) && Image3 -> Visible == true)
   {x = -x; y = -y; Image3 -> Visible = false; to_win--;}

   // block 4
   if(strike(ball, Image4) && Image4 -> Visible == true)
   {x = -x; y = -y; Image4 -> Visible = false; to_win--;}

   // block 5
   if(strike(ball, Image5) && Image5 -> Visible == true)
   {x = -x; y = -y; Image5 -> Visible = false; to_win--;}

   // block 6
   if(strike(ball, Image6) && Image6 -> Visible == true)
   {x = -x; y = -y; Image6 -> Visible = false; to_win--;}

   // block 7
   if(strike(ball, Image7) && Image7 -> Visible == true)
   {x = -x; y = -y; Image7 -> Visible = false; to_win--;}

   // block 8
   if(strike(ball, Image8) && Image8 -> Visible == true)
   {x = -x; y = -y; Image8 -> Visible = false; to_win--;}

   // block 9
   if(strike(ball, Image9) && Image9 -> Visible == true)
   {x = -x; y = -y; Image9 -> Visible = false; to_win--;}

   // block 10
   if(strike(ball, Image10) && Image10 -> Visible == true)
   {x = -x; y = -y; Image10 -> Visible = false; to_win--;}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftTimer(TObject *Sender)
{
  if(paddle -> Left > 10) paddle -> Left -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rightTimer(TObject *Sender)
{
  if(paddle -> Left + paddle -> Width < background -> Width - 10) paddle -> Left += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_LEFT) left -> Enabled = true;
  if(Key == VK_RIGHT) right -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_LEFT) left -> Enabled = false;
  if(Key == VK_RIGHT) right -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  ball -> Left = 50;
  ball -> Top = 50;

  ball -> Visible = true;
  x = -8; y = -8;
  timerball -> Enabled = true;

  Button1 -> Visible = false;
  to_win = 10;

  Image1 -> Visible = true;   Image2 -> Visible = true;    Image3 -> Visible = true;
  Image4 -> Visible = true;   Image5 -> Visible = true;    Image6 -> Visible = true;
  Image7 -> Visible = true;   Image8 -> Visible = true;    Image9 -> Visible = true;
  Image10 -> Visible = true;

}
//---------------------------------------------------------------------------
