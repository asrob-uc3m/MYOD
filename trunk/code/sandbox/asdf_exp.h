#ifndef ASDF_H
#define ASDF_H

extern Robot myod;
void asdf(){

int time_1 = 800;
int vector_1[22] = {90,90,157,90,22,90,90,86,69,81,90,91,90,76,92,92,88,91,97,99,86,90};
int time_2 = ;
int vector_2[22] = {90,90,157,12,22,90,90,60,69,81,90,91,90,76,92,92,88,91,97,99,86,90};
int time_3 = ;
int vector_3[22] = {90,90,157,12,22,90,90,60,69,81,90,91,90,76,92,92,88,91,97,99,86,90};
int time_4 = ;
int vector_4[22] = {90,90,157,12,22,90,106,60,69,81,90,91,90,76,92,92,88,91,97,99,86,90};
int time_5 = ;
int vector_5[22] = {90,90,157,12,22,90,90,60,69,81,90,91,90,76,92,92,88,91,97,99,86,90};
int time_6 = ;
int vector_6[22] = {90,90,157,12,22,90,90,60,69,81,90,91,90,76,92,92,88,91,97,99,86,90};
int time_7 = ;
int vector_7[22] = {90,90,157,90,22,90,90,86,69,81,90,91,90,76,92,92,88,91,97,99,86,90};


myod.move(time_1, vector_1);
myod.move(time_2, vector_2);
myod.move(time_3, vector_3);
myod.move(time_4, vector_4);
myod.move(time_5, vector_5);
myod.move(time_6, vector_6);
myod.move(time_7, vector_7);

}

#endif