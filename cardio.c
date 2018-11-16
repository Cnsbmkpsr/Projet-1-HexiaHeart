#include "cardio.h"

void current_pulse()
{
	int previousvalue = 0;
	long previoustmp = 0;
	int actualvalue, thresholdvalue;
	long detectiontmp;

	actualvalue = analogRead(A0);
	thresholdvalue = 360;

	if (actualvalue > thresholdvalue)
	{
		if (previoustmp <= thresholdvalue)
		{
			detectiontmp = millis();
			if (detectiontmp > (previoustmp + 200))
			{
				Serial.println(actualvalue);
				previoustmp = detectiontmp;

			}
		}

	}

	previousvalue = actualvalue

}


int delay()
{
      Serial.println("Time: ");
      int Time = millis();
      Serial.println(Time);
}
