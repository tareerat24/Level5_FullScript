void SentData(int item_selected)
{
  Serial.print(item_selected);
  switch (item_selected) 
  {
    case 1:
      Serial1.print("1"); //Show Temp humi, Light and Distance sent to level1-2
      break;

    case 2:
      Serial2.print("1"); //Robot dance sent to level 4
      break;

    case 3:
      Serial1.print("2"); //Sent Auto Car to level 1-2
      break; 

    case 4:
      Serial1.print("8"); //Sent stop to level 1-2
      Serial2.print("8"); //Sent stop to level 4
      break;

    case 5:
      Serial2.print("4"); //Show Red nepixel 2 eyes sent to level 4
      break;

    case 6:
      Serial2.print("2"); //HandGripe sent to level 4
      break;

    case 7:
      Serial2.print("3"); // HandRelease sent to level 4
      break;

    case 8:
      Serial1.print("4"); // Speak sent to level 1-2
      break;

    case 9:
      Serial1.print("5"); // Car is a Triangle sent to level 1-2
      break;
    
    case 10:
      Serial1.print("6"); // Car is a Rectangle sent to level 1-2
      break;

    case 11:
      Serial2.print("5"); // Eye Blink sent to level 4
      break;

    case 12:
      Serial2.print("6");//Rainbow sent to level 4
      break;

    case 13:
      Serial1.print("7"); //Flashlight sent to level 1-2
      break;

    case 14:
      Serial2.print("13");
      delay(500);
      Serial1.print("10");
      break;

    case 0:
      Serial1.print("9"); //Sent Restart to level 1-2
      Serial2.print("9"); //Sent Restart to level 4
      resetFunc();
      break;

    default:
      break;
  }
}