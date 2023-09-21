#include <iostream>
#include <string>
#include <stdlib.h>

struct alumno
{
    std::string nombre;
    int matricula;
    float calif[3];
};

int main(){
    bool on_prog = true;
    std::cout<<"Bienvenid@ al programa de registro y promedio de calificaciones"<<std::endl;
    std::cout<<std::endl;
    int index = 0;
    int opt = 0;
    alumno listAlumn[15];
    float promedios[15];
    while (on_prog)
    {
        std::cout<<"Ingrese 1 para registrar al siguiente alumno"<<std::endl;
        std::cout<<"Ingrese 2 para mostrar los alumnos registrados"<<std::endl;
        std::cout<<"Ingrese 3 para salir"<<std::endl;
        std::cin>>opt;
        std::cout<<std::endl;
        if (opt == 1)
        {
            std::cout<<"Escriba el nombre del alumno "<<index<<std::endl;
            std::cin>>listAlumn[index].nombre;
            
            for (int i = 0; i < 3; i++)
            {
                std::cout<<"Escriba la calificacion del alumno "<<index<<" en el parcial "<<i+1<<std::endl;
                std::cin>>listAlumn[index].calif[i];
            }
            std::cout<<"Escriba la matricula del alumno "<<index<<std::endl;
            std::cin>>listAlumn[index].matricula;
            std::cout<<std::endl;
            index++;

        }else if (opt == 2)
        {
            if (index==0)
            {
                std::cout<<"No hay alumnos registrados, intentelo de nuevo"<<std::endl;
            }else{
                std::cout<<"Hay "<<index + 1<<" alumnos en la lista de alumnos"<<std::endl;
                for (int i = 0; i < index; i++)
                {
                    std::cout<<"Alumno: "<<i<<"\tNombre:"<<listAlumn[i].nombre<<" \tMatricula: "<<listAlumn[i].matricula<<std::endl;
                    std::cout<<"Calificaciones: ";
                    
                    float sum = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        
                        if (j == 0)
                        {
                            sum = sum + ((listAlumn[i].calif[j])*0.3);
                        }else if (j==1)
                        {
                            sum = sum + ((listAlumn[i].calif[j])*0.3);
                        }
                         if (j == 2)
                        {
                            sum = sum + ((listAlumn[i].calif[j])*0.4);
                        }
                        std::cout<<"\tParcial "<<j+1<<": "<<listAlumn[i].calif[j];
                    }
                    std::cout<<"\tPromedio ordinario(30%,30%,40%): "<<sum<<std::endl;
                    std::cout<<std::endl;
                    promedios[i] = sum;
                }
                float prom = 0;
                for (int i = 0; i < index; i++)
                {
                    prom = prom + promedios[i];
                }
                std::cout<<"Promedio final total de todos los alumnos: "<<prom/index<<std::endl;
                std::cout<<std::endl;
            }
        }else if (opt == 3)
        {
            std::cout<<"Fin de la ejecucion..."<<std::endl;
            std::cout<<"Vuelva pronto"<<std::endl;
            on_prog=false;
        }else
        {
            std::cout<<"Opcion no valida, intentelo de nuevo"<<std::endl;
        }
    }
    
    return 0;
}