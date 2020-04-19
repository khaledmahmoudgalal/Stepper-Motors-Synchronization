// khaled mahmoud galal [pm]
// 13/2/2019
// a little bit complex algorithm for synchronizing the motion
// the code works to recive 6 values of steps to be directed and writen on the 6 motors.
// works with uart serial communication protocol
// blutooth , serial monitor , and other software programs can be used to send the values

#include <Stepper.h>  

#define STEPS 200

Stepper BaseRotation(STEPS, 2 , 3  ); // (Nom of steps per revolution , step pin , dir pin )

Stepper ConectOneUpDown(STEPS, 4 , 5  );

Stepper ConectTwoRotation(STEPS, 6 , 7  );

Stepper ConectTwoUpDown(STEPS, 8 , 9  );

Stepper ConectThreeRotation(STEPS, 10 , 11  );

Stepper ConectThreeUpDown(STEPS, 12 , 13  );

void setup() {
  
  Serial.begin(9600);
  BaseRotation.setSpeed(60);
  ConectOneUpDown.setSpeed(60);
  ConectTwoRotation.setSpeed(60);
  ConectTwoUpDown.setSpeed(60);
  ConectThreeRotation.setSpeed(60);
  ConectThreeUpDown.setSpeed(60);
  
}

void loop() {

 if (Serial.available() > 0) {
  
   int reading[6];
   int onlypositive[6];
   int maxnom ;

// reading the inputs :
   
   for (int i=0;i<6;i++) {
    reading[i]={Serial.parseInt()}; }

    Serial.println (reading[0]) ;
    Serial.println (reading[1]) ;
    Serial.println (reading[2]) ;
    Serial.println (reading[3]) ; 
    Serial.println (reading[4]) ;
    Serial.println (reading[5]) ;

// geting only positive values :

    for (int i=0;i<6;i++) {
    if ( reading[i]<0 )
    { onlypositive[i]=-reading[i] ; }
    else { onlypositive[i]=reading[i] ; } }
    
    Serial.println (onlypositive[0]) ;
    Serial.println (onlypositive[1]) ;
    Serial.println (onlypositive[2]) ;
    Serial.println (onlypositive[3]) ;
    Serial.println (onlypositive[4]) ;
    Serial.println (onlypositive[5]) ;

    // geting the maximum nom :
    
    maxnom=onlypositive[0];
    for (int i=0;i<6;i++) {
    if ( onlypositive[i]>maxnom )
    { maxnom=onlypositive[i] ; } }
    
    Serial.println(maxnom);

// the great loop ( el ma3gana ) :

    for ( int k=0 ; k <= maxnom ; k++ ) {
      
   // The first motor :
    
    if ( k < onlypositive[0] )            {
      
    if (reading[0]<0) {
      BaseRotation.step(-1);  }

    else if (reading[0]>0) {
      BaseRotation.step(1); }             }
    
    else if ( k > onlypositive[0] ) {
      BaseRotation.step(0); Serial.println(k); //check
                                          }
                                         
     
    // The second motor :
    
    if ( k < onlypositive[1] )            {
      
    if (reading[1]<0) {
      ConectOneUpDown.step(-1);  }

    else if (reading[1]>0) {
      ConectOneUpDown.step(1); }          }
    
   else if ( k > onlypositive[1] ) {
      ConectOneUpDown.step(0); }
    
                                          
                                     
      // The third motor :
    
    if ( k < onlypositive[2] )            {
      
    if (reading[2]<0) {
      ConectTwoRotation.step(-1);  }

    else if (reading[2]>0) {
      ConectTwoRotation.step(1); }        }
    
    else if ( k > onlypositive[2] ) {
      ConectTwoRotation.step(0); }
    
                                           
     
     // The fourth motor :
    
    if ( k < onlypositive[3] )             {
      
    if (reading[3]<0) {
      ConectTwoUpDown.step(-1);  }

    else if (reading[3]>0) {
      ConectTwoUpDown.step(1); }           }
    
    else if ( k > onlypositive[3] ) {
      ConectTwoUpDown.step(0); }
    
                                           
     
    // The Fifth motor :
    
    if ( k < onlypositive[4] )             {
      
    if (reading[4]<0) {
       ConectThreeRotation.step(-1);  }

    else if (reading[4]>0) {
       ConectThreeRotation.step(1); }      }
    
    else if ( k > onlypositive[4] ) {
       ConectThreeRotation.step(0); }
    
                                           
                                     
      // The six motor :
    
    if ( k < onlypositive[5] )             {
      
    if (reading[5]<0) {
      ConectThreeUpDown.step(-1);  }

    else if (reading[5]>0) {
      ConectThreeUpDown.step(1); }         }
    
    else if ( k > onlypositive[5] ) {
      ConectThreeUpDown.step(0); }
    
                                                                                            
                                                             
                                                             
                                                         }        
                                                                     
                                                                    }
    
     else    { 
                 BaseRotation.step(0);
                 ConectOneUpDown.step(0);
                 ConectTwoRotation.step(0);
                 ConectTwoUpDown.step(0);
                 ConectThreeRotation.step(0);
                 ConectThreeUpDown.step(0);
                                                   }


}
