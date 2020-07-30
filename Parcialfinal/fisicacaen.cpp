#include "fisicacaen.h"
#include "math.h"
#include "cmath"
Fisicacaen::Fisicacaen(float posX_, float posY_, float VelX_, float VelY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_;
    PY = posY_;
    mass = masa_;
    R = radio_;
    VX= VelX_;
    VY = VelY_;
    AX = 0;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;


}

Fisicacaen::~Fisicacaen()
{

}

float Fisicacaen::get_PosX()
{
    return PX;
}

float Fisicacaen::get_PosY()
{
    return PY;
}

float Fisicacaen::get_Radio()
{
    return R;
}

float Fisicacaen::get_masa()
{
    return mass;
}

float Fisicacaen::get_e()
{
    return e;
}

int Fisicacaen::grat()
{
    return G;
}

void Fisicacaen::Newgra(int GR)
{
    G=GR;
}

float Fisicacaen::get_VelX()
{
    return VX;
}

float Fisicacaen::get_VelY()
{
    return VY;
}

void Fisicacaen::set_vel(float velx, float vely, float px, float py)
{
      VX = velx;
      VY = vely;
      PX = px;
      PY = py;
}

void Fisicacaen::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2);
    angulo =atan2(VY,VX);
    AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
    AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
    PX = PX+ (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY+ (VY*dt) + ((AY*(dt*dt))/2);
    VX = VX +AX*dt;
    VY = VY +AY*dt;

}
