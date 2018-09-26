int full = 9999;
	int  mid = 2499;
	int full70 = 2999;//for mapping 50+20
	int full20 = 1999;//for mapping 50-20
/*4 quadrant 
1st is 12-3pm
2nd is 3-6pm
3rd is 6-9pm
4th is 9-12pm

8 octant
1st 12-1:30pm
2nd 1:30 -3pm
3rd 3-4:30pm
4th 4:30-6pm
5th 6-7:30pm
6th 7:30pm-9pm
7th 9-9:30
8th 9:30-12pm


left connection
gpio-pe13
pwm-pe9, setcompare1

right connection
gpio - pe12
pwm - pe11,setcompare2


*/
	if(x<full70 && y<full70 && x>full20 && y>full20 && )//zero- zero (joy1)
	{
GPIO_ResetBits(GPIOE,GPIO_Pin_13);
		TIM_SetCompare1(TIM1, 0);

GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		TIM_SetCompare2(TIM1, 0);


	}

	else if(x<=full70 && x>=full20 && y>=full70)//full forward (joy2)

	{

		GPIO_SetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, (y-mid)*gear);

                 GPIO_SetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, (y-mid)*gear);		

		
	}

	else if(x<=full70 && x>=full20 && y<=full20)//full backward (joy2)
	{

		 GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, (mid-y)*gear);

                 GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, (mid-y)*gear);

		
	}

	else if(x<full70 && y<full70 && x>full20 && y>full20 && x=0 && y=4999)//360 left (joy1)
	{

	{
               GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, mid*gear);

                 GPIO_SetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, mid*gear);

		
	}

	else if(x<full70 && y<full70 && x>full20 && y>full20 && x=9999 && y=4999)//360 right (joy1)

	{
 		 GPIO_SetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, mid*gear);

                 GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, mid*gear);

	}
	
	
	else if(y>full20 && y<full70 && x<full20)//soft left
	{

		 GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, 0);

                 GPIO_SetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, (mid-x)*gear);
		
	}
	else if(y>full20 && y<full70 && x>full70)//soft right
	{

		
		 GPIO_SetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, (x-mid)*gear);

                 GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, 0);

		
	}

	if(x>full70 && y>=full70)//Upper-Right
	{
		if(y>=x)//Right of F
		{
			x = map(x,full70,full,full70,mid+0.5*mid);
			x=y-x;

		 GPIO_SetBits(GPIOE,GPIO_Pin_13);
	       TIM_SetCompare1(TIM1, (y-mid)*gear);

                 GPIO_SetBits(GPIOE,GPIO_Pin_12);
		 TIM_SetCompare2(TIM1, x*gear);
			

		}
		else//Up of Right
		{
			y = map(y,full70,full,full,mid+0.5*mid);
			x = map(x,full70,full,mid+0.5*mid,full);
			if ((x-y)>=0)
			{
				y=x-y;

				 GPIO_SetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, (x-mid)*gear);

               			  GPIO_SetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, x*gear);

			 
			}
		}
	}
	else if(x<full20 && y>full70)//Upper-Left
	{
		x=full-x;
		if(y>x)//Left of F
		{
			x = map(x,full,full70,mid+0.5*mid,full70);
			x=y-x;

			 GPIO_SetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, x*gear);

               			  GPIO_SetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, (y-mid)*gear);


			
		}
		else
		{
			
			y = map(y,full,full70,mid+0.5*mid,full);
			x = map(x,full70,full,mid+0.5*mid,full);
			if ((x-y)>=0)
			{
				y=x-y;

				GPIO_SetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, y*gear);

               			  GPIO_SetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, (x-mid)*gear);

			}
		}
	}
	else if(x<full20 && y<full20)//Bottom-Left
	{
		x=full-x;
		y=full-y;
		if(y>=x)//Left Back
		{
			x=y-x;

			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, (y-mid)*gear);

               			  GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, x*gear);

		}
		else //Bottom of Left
		{

			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, 0);

               			  GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, 0);

		}
	}
	else if(x>full70 && y<full20)//Bottom-Right
	{
		y=full-y;
		if(y>=x)//Right of Back
		{
			x=y-x;

			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, x*gear);

               			  GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, (y-mid)*gear);

			
		}
		else //Bottom of Right
		{
			y=x-y;

			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	               		 TIM_SetCompare1(TIM1, 0);

               			  GPIO_ResetBits(GPIOE,GPIO_Pin_12);
		    		  TIM_SetCompare2(TIM1, 0);

			
		}
	}
	
}