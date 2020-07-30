#ifndef FISICACAEN_H
#define FISICACAEN_H


class Fisicacaen
{
public:

     Fisicacaen(float posX_,float posY_,float VelX_,float VelY_,float masa_,float radio_,float K_,float e_);
    ~ Fisicacaen();
    float get_PosX();
    float get_PosY();
    float get_Radio();
    float get_masa();
    float get_e();
    int grat();
    void Newgra(int GR);
    float get_VelX();
    float get_VelY();
    void set_vel(float vo, float anguI,float px,float py);
    void actualizar();
private:
    float PX,PY,mass,R,VX,VY,angulo,AX,AY,G,K,e,V,dt;

};

#endif // FISICACAEN_H
