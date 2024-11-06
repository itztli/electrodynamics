// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/GPL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "numeric.h"
#include "model.h"
#include "particle.h"

//MKS system

int main(int argn, char **args){

  Integrator trapezio,riemann;
  Model model3body;
  Particle particle1,particle2,particle3;

  double q1,q2,q3,m1,m2,m3,m_e;
  double x1,x2,x3, y1,y2,y3, z1,z2,z3;
  double vx1,vx2,vx3, vy1,vy2,vy3, vz1,vz2,vz3;
  //  double ax1,ax2,ax3, ay1,ay2,ay3, az1,az2,az3;

  char name[128];
  int N;

  int integrator; // 0: default (trapezium)
  double dt;

  m_e = 9.1093837015e-31; //[Kg] electron mass
  // Initial conditions
  //integrator
  integrator = 1; //0:trapezium 1:Riemann

  dt = 1e-35;//0.001; //sec
  
  // Model
  //sscanf("3 Body","%s",name);


  N = 3;
  
  //particle 1 (electron)
  q1 = -1.6e-19; // Coulombs
  m1 = m_e;
  x1 = 0.0;  //m
  y1 = 0.0;  //m
  z1 = 0.0; //m
  
  vx1 = 0.0;  // m/s
  vy1 = 0.0;  // m/s
  vz1 = 0.0; //  m/s

 
  //particle 2 (electron)
  q2 = -1.6e-19; //chargue
  m2 = m_e;
  x2 = 5.3e-11;  //m (100pm)
  y2 = 0.0;  //m
  z2 = 0.0; //m
  
  vx2 = 0.0;  // m/s
  vy2 = 0.0;  // m/s
  vz2 = 0.0; //  m/s

  //particle 3 (electron)
  q3 = -1.6e-19; //chargue
  m3 = m_e;
  x3 = 1.6e-10;  //m (200pm)
  y3 = 0.0;  //m
  z3 = 0.0; //m
  
  vx3 = 0.0;  // m/s
  vy3 = 0.0;  // m/s
  vz3 = 0.0; //  m/s

  
  particle1 = new_Particle(q1, m1, x1, y1, z1, vx1, vy1, vz1);
  particle2 = new_Particle(q2, m2, x2, y2, z2, vx2, vy2, vz2);
  particle3 = new_Particle(q3, m3, x3, y3, z3, vx3, vy3, vz3);

  model3body = new_Model("3Body system", N);
  printf("#3body %i\n",model3body.N);
  
  printf("#Welcome to n-body!\n");
  add_Particle_to_Model(&model3body,particle1);
  //printf("model.i=%i\n",model3body.i);
  add_Particle_to_Model(&model3body,particle2);
  //printf("model.i=%i\n",model3body.i);
  add_Particle_to_Model(&model3body,particle3);
  //printf("model.i=%i\n",model3body.i);
  //printf("Integrator %i\n",integrator);
  
  riemann = new_integrator(integrator,dt);

  printf("%i\n",model3body.i);
  for(int i=0; i< 300000;i++){    
    model3body = integrator_solve(riemann, model3body);
    if ((i % 3000) == 0){
      printf("#%i\n",i);
      print_Model(model3body);
    }
  }
  close_Model(&model3body);
  return 0;
}
