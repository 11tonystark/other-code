while(1)
	{
		d=USART_ReceiveData(UART4);


				// dp=d;
			     if(d=='n')
				{
                    motor= uartreceive();

			    	 GPIO_SetBits(GPIOE,GPIO_Pin_8);
			    	 if(motor=='A')//E
			    	 {
			    	 		 //linear act, f
			    	 			GPIO_SetBits(GPIOA,GPIO_Pin_4);//dirc
			    	 			GPIO_SetBits(GPIOA,GPIO_Pin_5);//gpio
			    	 }

			    	 	else if(motor=='B')//F
			    	 		{//linear act.  b
			    	 			GPIO_SetBits(GPIOA,GPIO_Pin_4);//dirc
			    	 			GPIO_ResetBits(GPIOA,GPIO_Pin_5);//gpio
					//continue;
			     	         }
			    	 		
			    	 		else if(motor=='J')
			    	 			{//roll  b
			    	 			Stopthearm();
			    	 			}


				}

			 	else if (d!='n')
			 					{
			 					 Stopthearm();
			 					 GPIO_ResetBits(GPIOE,GPIO_Pin_8);
			 				
			 					//continue;
			 					}


	}


}
			