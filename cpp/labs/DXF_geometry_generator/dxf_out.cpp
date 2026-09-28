/******************************************************************/
/*                     dxf_out                                    */
/*                     =======                                    */
/*    Функции  вывода  графических  примитивов AutoCAD            */
/*              в dxf-файл текстового формата                     */
/******************************************************************/
#include  <stdio.h>
#include  <math.h>
#include  <stdlib.h>

// КОДЫ  ОСНОВНЫХ  ЦВЕТОВ  СИСТЕМЫ  AUTOCAD 

#define  WHITE     7     //  белый
#define	 YELLOW    2     //  желтый
#define	 BROWN    10     //  коричневый
#define	 GREEN     3     //  зеленый
#define	 CYAN      4     //  голубой
#define	 BLUE      5     //  синий
#define	 MAGENTA   6     //  фиолетовый
#define  RED       1     //  красный
/*-------------------------*/
/*  ГЛОБАЛЬНЫЕ  ПЕРЕМЕНЫЕ  */
/*-------------------------*/
int    dxf_color=RED;
char   layer[200]="0";

// Прототипы функций

void  dxf_mark_value (FILE *, int , int    );
void  dxf_mark_value (FILE *, int , double );
void  dxf_mark_value (FILE *, int , const char  *);

void  dxf_coor (FILE *, int , double []); 

FILE  *dxf_init(const char *);
void   dxf_end (FILE *);
void   dxf_layer(const char *);
void   dxf_line (FILE *, double [], double []);
//  void   dxf_lwpolyline (FILE *, double [][3], int , double);
void   dxf_text  (FILE *, 
				   double [],
                   char *,
                   double ,
                   double 
				  );
void   dxf_circle  (FILE *, 
				   double [],
                   double 
				  );



/******************************************************************/
/*                     dxf_mark_value                             */
/*                     ==============                             */
/*  Функции  вывода  в  dxf-файл пары  маркер-значение            */  
/******************************************************************/
// маркер-целое
void dxf_mark_value (FILE *dxf, int marker, int value)
{
 fprintf(dxf,"%3d\n%d\n",marker,value) ;
}
// маркер-действительное
void dxf_mark_value (FILE *dxf, int marker, double value)
{
 fprintf(dxf,"%3d\n%lf\n",marker,value) ;
}
// маркер-строка
void dxf_mark_value (FILE *dxf, int marker, const char *value)
{
 fprintf(dxf,"%3d\n%s\n",marker,value) ;
}

/******************************************************************/
/*                          dxf_init                              */
/*                          ========                              */
/*                   Инициализация    dxf-файла                   */  
/******************************************************************/


FILE *dxf_init(const char *dxf_name)
{
   FILE *file_dxf;
   errno_t err;
   if(err=fopen_s(&file_dxf, dxf_name,"wt")!=0)
   {
     printf("\nCannot open the file %s!\nThis file is already opened into AutoCAD\n",dxf_name);
     exit(-1); 
   }

   dxf_mark_value(file_dxf,0,"SECTION");
   dxf_mark_value(file_dxf,2,"ENTITIES");

   return(file_dxf);
}

/******************************************************************/
/*                          dxf_end                               */
/*                          =======                               */
/*                      Закрытие dxf-файла                        */  
/******************************************************************/
void  dxf_end(FILE *file_dxf)
{
  dxf_mark_value(file_dxf,0,"ENDSEC");
  dxf_mark_value(file_dxf,0,"EOF");

  fclose(file_dxf);
}

/******************************************************************/
/*                        dxf_layer                               */
/*                        =========                               */
/*                    Установить   слой                           */  
/******************************************************************/
void   dxf_layer(const char *cur_layer)
{
   snprintf(layer,80,"%s",cur_layer);
}

/******************************************************************/
/*                        dxf_coor                                */
/*                        ========                                */
/*        Запись  координаты  точки в dxf-файл                    */  
/******************************************************************/
void dxf_coor  (FILE *file_dxf, int num_coor , double pt[])
{
   dxf_mark_value(file_dxf,10+num_coor,pt[0]);	
   dxf_mark_value(file_dxf,20+num_coor,pt[1]);	
   dxf_mark_value(file_dxf,30+num_coor,pt[2]);	
}

/******************************************************************/
/*                        dxf_line                                */
/*                        ========                                */
/*                Запись  линии в dxf-файл                        */  
/******************************************************************/
void   dxf_line (FILE *file_dxf, double pt1[], double pt2[])
{
   dxf_mark_value(file_dxf,0,"LINE");
   dxf_mark_value(file_dxf, 8,layer);
   dxf_mark_value(file_dxf,62,dxf_color);

   dxf_coor(file_dxf, 0 , pt1); 
   dxf_coor(file_dxf, 1 , pt2); 
}

/******************************************************************/
/*                        dxf_text                                */
/*                        ========                                */
/*                Запись  текста в dxf-файл                     */  
/******************************************************************/
void   dxf_text  (FILE *file_dxf, 
				   double pt[],
                   char *text,
                   double h,
                   double ang
				  )
{
	
   dxf_mark_value(file_dxf,0,"TEXT");
   dxf_mark_value(file_dxf, 8,layer);
   dxf_mark_value(file_dxf,62,dxf_color);

   dxf_coor(file_dxf, 0 , pt );
   
   dxf_mark_value(file_dxf,40,h);
   dxf_mark_value(file_dxf,1,text);
   dxf_mark_value(file_dxf,50,ang);

}


/******************************************************************/
/*                        dxf_circle                              */
/*                        ========                                */
/*                Запись  круга в dxf-файл                       */  
/******************************************************************/
void   dxf_circle  (FILE *file_dxf, 
				   double pt[],
                   double r
				  )
{
	
   dxf_mark_value(file_dxf,0,"CIRCLE");
   dxf_mark_value(file_dxf, 8,layer);
   dxf_mark_value(file_dxf,62,dxf_color);

   dxf_coor(file_dxf, 0 , pt );
   
   dxf_mark_value(file_dxf,40,r);
}


/******************************************************************/
/*                        dxf_lwpolyline                          */
/*                        ==============                          */
/*                Запись  полилинии линии в dxf-файл              */  
/******************************************************************/
void   dxf_lwpolyline (FILE *file_dxf, double mas_pt[][3], int all_pt ,double  w_pline)
{
   int i;

   dxf_mark_value(file_dxf,0,"LWPOLYLINE");
   dxf_mark_value(file_dxf,5,"1D");
   dxf_mark_value(file_dxf,100,"AcDbEntity");
   dxf_mark_value(file_dxf, 8,layer);
   dxf_mark_value(file_dxf,100,"AcDbPolyline");
   dxf_mark_value(file_dxf,62,dxf_color);


   dxf_mark_value(file_dxf,90,all_pt);
   dxf_mark_value(file_dxf,70,0);
   dxf_mark_value(file_dxf,43,w_pline);

   for(i=0; i<all_pt ; i++)
      dxf_coor(file_dxf, 0 , &mas_pt[i][0]); 
  
}


