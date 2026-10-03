
#include <stdio.h>
//#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "randomGenerator.h"

// تعرض عدًّا تنازليًا قبل رمية النرد.
    void suspense(){

printf("Press Enter to roll the dice:  ");
getchar();
while (getchar()=='\n') {
  printf("Are you ready the Dice is rolling\n");
for(int i = 3; i > 0; i--){
  printf("%d \n",i);
  sleep(1);

}

break;
}

}
  // نمط الرمية الأولى: يفوز اللاعب إذا أظهر النرد الرقم 6.
    void first_shot(random_number_generator *rng){
    printf("You have chosen the first shot mod, now you will try to win 6 with the first throw\n");
  suspense();

int dice = get_next_range(&*rng, 6) + 1;
if(dice == 6){
  printf("You have won the game with the first throw, congratulations!\n");

}
else{
  printf("You have not won the game with the first throw you rolled %d, better luck next time!\n",dice);
}
}
  // نمط التحدي: يجمع اللاعب نتائج أربع رميات ويحاول بلوغ 18 نقطة.
    void SteelBallRun(random_number_generator *rng){
printf("You have 4 free throws to score over 18 points or you lose\n");
suspense();
int total = 0;
for (int i = 4; i>0; i--) {
int roll = get_next_range(&*rng, 6) + 1;
printf("You rolled %d \n" , roll);
sleep(1);
total+=roll;
}
if (total >= 18) {
printf("you win");
}
else {
printf("You lose your total is %d" , total);
} 
}
  // نمط القتال: تتناوب رميات اللاعب والخصم حتى تنفد صحة أحدهما.
    void The_Fight(random_number_generator *rng) {
      printf("You will enter a fight !!!! \n");
      printf("Both you and your oponent have 15 hp \nThe only way to deal damage is to roll the dice\n");
      sleep(3);
      printf("The one who roll bigger number win the round and he can deal damage as he rooled\n");
      sleep(2);
      printf("the first one who reach 0hp lose the game \n");
      sleep(2);
      int Player_hp=15;
      int Oponent_hp=15;
      // تستمر الجولات ما دامت صحة الطرفين أكبر من صفر.
      while (Player_hp > 0 && Oponent_hp>0) {
        printf("Oponent's Turn\n");
          printf("Are you ready the Dice is rolling\n");
          for(int i = 3; i > 0; i--){
          printf("%d \n",i);
          sleep(1);}
      int Oponent_roll =get_next_range(&*rng, 6) + 1;
      printf("The oponent rolled %d\n " , Oponent_roll);
      sleep(1);
      printf("Your turn\n");
      suspense();     
 
      
      sleep(1);
      
      int player_roll = get_next_range(&*rng, 6) + 1; 
       printf("You rolled %d\n " , player_roll);
      if (Oponent_roll> player_roll) {
        Player_hp = Player_hp - Oponent_roll;
        printf("You lost the round your hp become %d\n" , Player_hp);
        sleep(3);
        
      }
      else if (Oponent_roll < player_roll) {
        Oponent_hp = Oponent_hp - player_roll;
      printf("You win the round Oponent's hp become %d\n" , Oponent_hp);
      sleep(3);
      }
      else {
      printf("DRAW");
      }
      }
      // حدّد الفائز حسب الطرف الذي نفدت نقاط صحته.
      if (Player_hp<0) {
      printf("You lost the fight");
      }
      else {
      printf("You win the fight Congratiolations!!");
      }
    }
    // نمط قصر الدم: اجمع نقاطًا لتجاوز الأهداف، وتجنب الرقم 1 ثلاث مرات.
    void Blood_Palace(random_number_generator *rng){
    printf("Welcome in the blood palace!\n");
    sleep(1);
    printf("This is a relentless test of risk and reward. Your goal is to ascend the tower by gathering points\nbut danger lurks in every roll.\n");
    sleep(3);
    printf("The Goal: Roll the dice to accumulate points. Beat the target score to advance to the next floor. The target increases as you climb higher!\n");
    sleep(3);
    printf("The Curse: The number 1 is a deadly trap. Every time you roll a 1, you earn zero points and receive a strike.\n");
    sleep(3);
    printf("The End: Accumulate 3 strikes, and your run is permanently over.\n"); 
    int strike = 0; // عدد مرات ظهور الرقم 1.
    int floor = 10; // النقاط المطلوبة لتجاوز الهدف الحالي.
    int total = 0;  // مجموع النقاط التي جمعها اللاعب.
    printf("The first floor you need to beat is %d" , floor);
    // تنتهي المحاولة عند تسجيل ثلاث ضربات.
    while (strike < 3) {
      suspense();
    // توليد نتيجة رمية واحدة، من 1 إلى 6.
    int roll =get_next_range(&*rng, 6) + 1; 
      if (roll == 1) {
      // الرقم 1 يضيف ضربة ولا يضيف نقاطًا.
      strike++;
      if (strike== 1) {
      printf("A chilling breeze sweeps through... You rolled a 1! (Strike 1/3)\n");
      }
           if (strike == 2) {
      printf(" The palace walls are closing in! Another 1! One more and you are doomed... (Strike 2/3)\n");
      }
      }
      else {
      // أضف نتيجة الرمية إلى مجموع النقاط.
      total+=roll;
      }
      if (total<floor) {
        printf("you rolled %d the path is still far\n ",roll);
      
      }
      else {
         printf("you rolled %d  ",roll);
      // عند بلوغ الهدف، زد النقاط المطلوبة للطابق التالي.
      printf("Target reached! The heavy doors slowly open to the next floor...\n");
      floor+=7;
      printf("You need to score %d to escape next floor " , floor);
      }


    }
    printf(" The dice shatter into dust. You rolled a 1 for the third time. The Blood Palace claims your soul!\n");
    printf("Your best score was %d good luck nest time!",floor);


    }




int main(){
  // تهيئة مولّد الأرقام العشوائية ببذرة مأخوذة من الوقت الحالي.
  random_number_generator rng = init((uint32_t)time(NULL));
  int option;
 // أعد عرض القائمة حتى يختار اللاعب الخروج.
 do{
  printf("-------------------Welcome to the Throwing dice Game!-------------------\n");

printf("there is 5 mods in this game, you can choose one of them to play\n");
sleep(1);
printf("1.The first shot\n");
sleep(1);
printf("2.Steel Ball Run \n");
sleep(1);
printf("3.The fight\n");
sleep(1);
printf("4.Blood palace\n");

printf("enter your option: ");
scanf("%d", &option);
// شغّل نمط اللعب الذي يطابق اختيار اللاعب.
switch(option){
  case 1 : 
  first_shot(&rng);
  break;
  case 2 :
  SteelBallRun(&rng);
  break;
    case 3 :
    The_Fight(&rng);
  break;
    case 4 :
  Blood_Palace(&rng);
  break;
  case 5:
  printf("\nThank you for playing! Goodbye.\n");
  break;
   default:
   printf("Enter a vailed option");
}
 }while(option != 5);
return 0;
}


