#ifndef funciones_H
#define funciones_H


int init_analisi_lexica(char *);
int end_analisi_lexica();

int init_analisi_sintactica(char *);
int end_analisi_sintactica(void);

int analisi_semantica(void);

void yyerror(char *explanation);

int init_log_file(char *filename);
int close_log_file(void);

#endif
