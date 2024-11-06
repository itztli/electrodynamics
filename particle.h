// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#ifndef PARTICLE_H
#define PARTICLE_H

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct{
    double q; //chargue
    double m; //mass
    double p[3]; //position
    double v[3]; //velocity
    double F[3]; //Force
  }Particle;

  Particle new_Particle(double q, double m, double x, double y, double z, double vx, double vy, double vz);

  void print_Particle(Particle particle);
  
#ifdef __cplusplus
}

#endif

#endif
