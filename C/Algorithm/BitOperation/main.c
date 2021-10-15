
#include "CAN.h"
#include <stdio.h> 
#include <stdlib.h>

static int endofcrc    =  0;




 void RemoveBit(__uint64_t *buffer , int bit_index);

 void IntToBinary (__uint64_t  a , char *b);


 void DeletedAddBit(__uint64_t *Frame , int *SequenceError , int *startFrame , char* NumberOfDeletedElement);

 int CAN_set_Paramter(__uint64_t *Frame , char *NumberodDeleted , int startpos);



__uint32_t Masking(char  a, char b);




int main()

{

//char b[100];
//char c[100];
//char d[100];



// __uint32_t Frame[4] ={0b10001000110000100000100000100000  ,0b10001000001010000010011000001100,   
  //                     0b00010010100000111000001011100101 ,0b00110001111011111111111111111111};
                                                             

//  char NumberofElement[2];                      



  //  __uint64_t Fist64Bit, Second64Bit;
   

 // Fist64Bit = Frame[1] | ((__uint64_t)  Frame[0] << 32);
 // Second64Bit = Frame[3] | ((__uint64_t)Frame[2] << 32);
  
 // int boolien;
 // int startposi; 
 
 

 // __uint64_t frame[2] = {Fist64Bit,Second64Bit};

 // DeletedAddBit(frame, &boolien , &startposi , NumberofElement );  

 // IntToBinary(frame[0],c);
 // IntToBinary(frame[1],d); 
  
  
 // printf("boolien = %d\nStartPos = %d\nDeleted Element First Half = %d\nDeleted Element Secon Half = %d\nframe[0]=%s\nframe[1]=%s\n",boolien,startposi,NumberofElement[0],NumberofElement[1],c,d);                

   
 // CAN_set_Paramter(frame ,NumberofElement, startposi);



  __uint8_t data[128] = {0b10000000,
                         0b00000000,
                         0b00000000,
                         0b00000000,
                         0b10000000,
                         0b00000000,
                         0b00000000, 
                         0b00000000,
                         0b10000000,
                         0b10000000, 
                         0b00000000,
                         0b00000000, 
                         0b00000000, 
                         0b00000000,  
                         0b10000000, 
                         0b00000000, 
                         0b00000000, 
                         0b00000000,  
                         0b00000000, 
                         0b00000000,  
                         0b10000000, 
                         0b00000000, 
                         0b00000000,  
                         0b00000000,  
                         0b00000000,  
                         0b00000000,  
                         0b10000000, 
                         0b00000000, 
                         0b00000000, 
                         0b00000000, 
                         0b00000000,  
                         0b00000000, 
                         0b10000000, 
                         0b00000000,  
                         0b00000000, 
                         0b00000000, 
                         0b10000000, 
                         0b00000000, 
                         0b00000000, 
                         0b00000000, 
                         0b00000000, 
                         0b00000000, 
                         0b10000000,  
                         0b00000000,   
                         0b10000000,  
                         0b00000000,  
                         0b00000000,  
                         0b00000000,
                         0b00000000,
                         0b00000000,
                         0b10000000,
                         0b00000000,
                         0b00000000,
                         0b10000000,
                         0b10000000,
                         0b00000000,
                         0b00000000,
                         0b00000000,
                         0b00000000,
                         0b00000000,
0b10000000, 
0b10000000,
0b00000000,
0b00000000,
0b00000000 ,
0b00000000,
0b00000000,
0b10000000,
0b00000000 ,
0b00000000,
0b10000000,
0b00000000 ,
0b10000000,
0b00000000,
0b00000000,
0b00000000 ,
0b00000000,
0b00000000,
0b10000000,
0b10000000,
0b10000000 ,
0b00000000,
0b00000000,
0b00000000,
0b00000000 ,
0b00000000,
0b10000000,
0b00000000,
0b10000000 ,
0b10000000,
0b10000000,
0b00000000 ,
0b00000000,
0b10000000,
0b00000000,
0b10000000 ,
0b00000000,
0b00000000,
0b10000000,
0b10000000,
0b00000000 ,
0b00000000,
0b00000000,
0b10000000,
0b10000000 ,
0b10000000,
0b10000000,
0b00000000,
0b10000000 ,
0b10000000,
0b10000000,
0b10000000 ,
0b10000000,
0b10000000,
0b10000000,
0b10000000 ,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000 ,
0b10000000,
0b10000000,
0b10000000,
0b10000000              
            };


  

  







/*


  int ErrorFound = 0;
  int j = 0;
 


  do
  {
     ErrorFound =  CAN_RxData_Set_Frame(data[j] , &endofcrc);
     j++;
  } while((ErrorFound == 0) && j < 128 );

  if(ErrorFound == 0)
    printf("HAL_OK\n");


printf("CAN Identification message = %d\nCAN DLC = %d\nCAN CRC = %d\n" , hcan.Message_Identifier , hcan.DLC, hcan.CRC);

for (int i =0; i <hcan.DLC; i++)
    printf("DATA[%i] = %d\n",i,hcan.RxData[i]);


hcan.Message_Identifier = 0x103;
CAN_Send_Message(hcan);


*/








    






//CAN_Paramater_Initialise(&endofcrc);
//char z[100];
/*
hcan.Message_Identifier = 0x103;
hcan.DLC                = 0b1000;
hcan.RxData[0] = 0b00000000;
hcan.RxData[1] = 0b00000001;
hcan.RxData[2] = 0b00000010;
hcan.RxData[3] = 0b00000011;
hcan.RxData[4] = 0b00000100;
hcan.RxData[5] = 0b00000101;
hcan.RxData[6] = 0b00000110;
hcan.RxData[7] = 0b00000111;
*/




//__uint16_t CRC = CRCCalculator();

//IntToBinary(CRC , z);

//printf("CRCMain = %d.\nBinary = %s\n",CRC,z);





hcan.Message_Identifier = 0x446;
hcan.DLC = 8;
hcan.CRC = 0;

for (int i = 0; i < 8;i++)
    hcan.RxData[i] = i;


printf("CRC = %d\n",CRCCalculator(&hcan));

 

 

 




    return 0; 
}




void RemoveBit(__uint64_t *buffer , int bit_index)
{
    /*
    Remove a bit at a specific index from an usigned long
    */
 
__uint64_t mask = -1ul << bit_index;
 *buffer =  (*buffer & ~mask)  | ((*buffer >> 1) & mask);

}






//void DeletedAddBit(__uint64_t *Frame , int *SequenceError , int *startFrame , char* NumberOfDeletedElement)
//{
    /*
    This Function Deleted Add Bit From the CAN Transmitter after five 0 the next bit should be 1 and this bit should be delted if it is not 1 or 0 after 5 seq of 1 
    then SequenceError will be 1 and the process of delted shoul be stoped and ACK Error should be produced. this function return Booelien Error and Number of deleted
    bit in the first and second Frame
    
    constructer: 
        -Frame : contain First and Second half of the CAN Frame
        
        -SequenceError: 0  if no ACK error it has be found
                       1  if  ACK Error has been found and the function will be immidiatly stoped

        -StartFrame: contain the position of start of frame after the Sequence of 1  from the EOF

        -NumberOfdletedElement: is a table that will contain number of deleted Elements in the first and second Half for the bit Operation  

    */
/*
     int addedBitFirstFrameCounter = 0; 
     int AddedBitSeconFrameCounter = 0;
     int bitStatus = 0; 
     int ZeroCounter = 0; 
     int OneCounter = 0;
     int PosOfRemovedbitsInTheFirstHalf[19]; 
     int PosOfRemovedbitsInTheSeconHalf[19];
     int startPos = 0;


     for (int i = 63 ; i >= 0 ; i--)
        {
            bitStatus = (Frame[0] >> i) & 1;

            if(bitStatus == 0)
                {
                    ZeroCounter++; 
                }

            else if(bitStatus == 1)
                {
                    ZeroCounter = 0; 
                } 

             if (ZeroCounter == 5)
                {
                    ZeroCounter = 0; 
                    
                    if(i != 0)
                    {
                    addedBitFirstFrameCounter++;
                    PosOfRemovedbitsInTheFirstHalf[addedBitFirstFrameCounter -1] = i -1;;
                    bitStatus = (Frame[0]>> (i-1)) & 1;
                    if(bitStatus ==1)
                        {
                            *SequenceError = 0;
                        }

                    else
                        {
                            *SequenceError =1;
                            return ;
                            break;
                        }
                
                }
                    else if( i == 0)
                    {
                        AddedBitSeconFrameCounter++;
                        PosOfRemovedbitsInTheSeconHalf[0] = 63;
                        bitStatus = (Frame[1] >>63) &1 ;
                          if(bitStatus ==1)
                        {
                            *SequenceError = 0;
                        }

                    else
                        {
                            *SequenceError =1;
                             return ;
                            break; 
                        }


                    }   
                }

                    }

       int j = 0;
       int boolFind = 0;
     



 do
 {

     bitStatus = (Frame[1]>> j) & 1;
     if(bitStatus == 0)
     {
         boolFind =1;
         startPos = j;
     }

     j++;
    
 }while((j <= 63) && ( boolFind == 0));





            if (AddedBitSeconFrameCounter == 0)
            {

                for (int i = 63; i>= startPos +1; i--)
                {
                    bitStatus = (Frame[1] >> i) &1;

                    if(bitStatus == 0)
                    {
                        ZeroCounter++;
                    }

                    else if(bitStatus ==1)
                    {
                        ZeroCounter = 0;
                    }

                    if(ZeroCounter == 5)
                    {
                        ZeroCounter = 0;
                        if( i != startPos)
                        {
                            AddedBitSeconFrameCounter++;
                            PosOfRemovedbitsInTheSeconHalf[AddedBitSeconFrameCounter-1] = i -1;
                            bitStatus = (Frame[1] >> (i-1)) &1;
                            if(bitStatus == 1)
                            {
                                *SequenceError = 0;
                            }
                            else 
                                {*SequenceError = 1;
                                 return ;
                                 break;
                                }                                                    
                        }
                    }

                }
            }

            else if(AddedBitSeconFrameCounter == 1)
            {

             for(int i = 62; i<=startPos;i--)
             {
 


           bitStatus = (Frame[1] >> i) &1;

                    if(bitStatus == 0)
                    {
                        ZeroCounter++;
                    }

                    else if(bitStatus ==1)
                    {
                        ZeroCounter = 0;
                    }

                    if(ZeroCounter == 5)
                    {
                        ZeroCounter = 0;
                        if( i != startPos)
                        {
                            AddedBitSeconFrameCounter++;
                            PosOfRemovedbitsInTheSeconHalf[AddedBitSeconFrameCounter -1] = i -1;
                            bitStatus = (Frame[1] >> (i-1)) &1;
                            if(bitStatus == 1)
                            {
                                *SequenceError = 0;
                            }
                            else 
                                {*SequenceError = 1;
                                 return ;
                                 break;
                                }                                                    
                        }
                    }


             }


            }




       
        for (int i = 0; i < addedBitFirstFrameCounter; i++)
        {
       
            RemoveBit(&Frame[0],PosOfRemovedbitsInTheFirstHalf[i]);
        }


        for(int i = 0; i < AddedBitSeconFrameCounter;i++)
        {
           RemoveBit(&Frame[1],PosOfRemovedbitsInTheSeconHalf[i]);
        }
       


  

        int LastAddbitseconframeCounter = AddedBitSeconFrameCounter;
        int LastAddbitFirstframecounter = addedBitFirstFrameCounter;




            for (int i = 63-addedBitFirstFrameCounter ; i >= 0 ; i--)
        {
            bitStatus = (Frame[0] >> i) & 1;

            if(bitStatus == 1)
                {
                    OneCounter++; 
                }

            else if(bitStatus == 0)
                {
                    OneCounter = 0; 
                } 

             if (OneCounter == 5)
                {
                    OneCounter = 0; 
                    
                    if(i != 0)
                    {
                    addedBitFirstFrameCounter++;
                    PosOfRemovedbitsInTheFirstHalf[addedBitFirstFrameCounter -1] = i -1;
                    bitStatus = (Frame[0] >> (i-1)) & 1;
                    if(bitStatus ==0)
                        {
                            *SequenceError = 0;
                        }

                    else
                        {
                            *SequenceError =1;
                             return ;
                            break;
                        }
                
                }
                    else if( i == 0)
                    {
                        AddedBitSeconFrameCounter++;
                        PosOfRemovedbitsInTheSeconHalf[AddedBitSeconFrameCounter] = 63;
                        bitStatus = (Frame[1] >>63) &1 ;
                          if(bitStatus ==0)
                        {
                            *SequenceError = 0;
                        }

                    else
                        {
                            *SequenceError =1;
                             return ;
                            break; 
                        }


                    }   
                }

                    }

     


            if (AddedBitSeconFrameCounter == LastAddbitseconframeCounter)
            {

                for (int i = 63-LastAddbitseconframeCounter; i>= startPos +1; i--)
                {
                    bitStatus = (Frame[1] >> i) &1;

                    if(bitStatus == 1)
                    {
                        OneCounter++;
                    }

                    else if(bitStatus ==0)
                    {
                       OneCounter = 0;
                    }

                    if(OneCounter == 5)
                    {
                        OneCounter = 0;
                        if( i != startPos)
                        {
                            AddedBitSeconFrameCounter++;
                            PosOfRemovedbitsInTheSeconHalf[AddedBitSeconFrameCounter-1] = i -1;
                            bitStatus = (Frame[1] >> (i-1)) &1;
                            if(bitStatus == 0)
                            {
                                *SequenceError = 0;
                            }
                            else 
                                {*SequenceError = 1;
                                 return ;
                                 break;
                                }                                                    
                        }
                    }

                }
            }

            else if(AddedBitSeconFrameCounter == LastAddbitseconframeCounter +1)
            {

             for(int i = 62 - LastAddbitseconframeCounter; i<=startPos;i--)
             {
 


           bitStatus = (Frame[1] >> i) &1;

                    if(bitStatus == 1)
                    {
                        OneCounter++;
                    }

                    else if(bitStatus ==0)
                    {
                        OneCounter = 0;
                    }

                    if(OneCounter == 5)
                    {
                        OneCounter = 0;
                        if( i != startPos)
                        {
                            AddedBitSeconFrameCounter++;
                            PosOfRemovedbitsInTheSeconHalf[AddedBitSeconFrameCounter -1] = i -1;
                            bitStatus = (Frame[1] >> (i-1)) &1;
                            if(bitStatus == 0)
                            {
                                *SequenceError = 0;
                            }
                            else 
                                {*SequenceError = 1;
                                 return ;
                                 break;
                                }                                                    
                        }
                    }


             }


            }







      for (int i = LastAddbitFirstframecounter; i < addedBitFirstFrameCounter; i++)
        {
       
            RemoveBit(&Frame[0],PosOfRemovedbitsInTheFirstHalf[i]);
        }


        for(int i = LastAddbitseconframeCounter; i < AddedBitSeconFrameCounter;i++)
        {
           RemoveBit(&Frame[1],PosOfRemovedbitsInTheSeconHalf[i]);
        }


     
     
     *startFrame = startPos;
     NumberOfDeletedElement[0] = addedBitFirstFrameCounter;
     NumberOfDeletedElement[1] = AddedBitSeconFrameCounter;



}

*/

/*
 int CAN_set_Paramter(__uint64_t *Frame , char *NumberodDeleted , int startpos)

 {

     /*
     Find Message Identifier , DLC , DATA  and CRC in Two usigned long Frame 
     */

    /* char b[100];
     
     __uint64_t r = createMask(53-NumberodDeleted[0],63-NumberodDeleted[0]);
     
     __uint64_t data = r & Frame[0];

      hcan.Message_Identifier = data >> (53UL - NumberodDeleted[0]);


      
      r  = createMask(46-NumberodDeleted[0] , 49- NumberodDeleted[0]);

      data = r & Frame[0];

      hcan.DLC =  data >> (46UL - NumberodDeleted[0]);

      int NumberofTransmittedbyte = hcan.DLC;

      if (NumberofTransmittedbyte == 0)

      {

          for(int i = 0; i < 8;i++)
          {
              hcan.Data[i] = 0x00;
          }

      }

      if (NumberofTransmittedbyte == 1)

      {
          
      }

      if (NumberofTransmittedbyte == 2)

      {
          
      }

      if (NumberofTransmittedbyte == 3)

      {
          
      }

      if (NumberofTransmittedbyte == 4)

      {
          
      }

      if (NumberofTransmittedbyte == 5)

      {
          
      }

      if (NumberofTransmittedbyte == 6)

      {
          
      }

      if (NumberofTransmittedbyte == 7)

      {
          
      }

      if (NumberofTransmittedbyte == 8)

      {
          
      }






     



      


   
 }

*/





__uint32_t Masking(char  a, char b)
{

   /*
   Create a Mask for a byte to find those bits.
   - a : should be the start bit index
   - b : should be the end bit index

   for exemeple to create a mask from bit 11 to 16
   of a world a = 11 , b = 16  
   */


   __uint32_t r = 0;
   for (unsigned i=a; i<=b; i++)
       r |= 1 << i;

   return r;
}