Pasos per compilar

    1. Crear fitxer a executar
    2. Definir fitxer a executar en linea 32 MakeFile
    3. Executar make clean
    4. Executar make all
    5. Sortida -> sortida.txt log.txt + errors per consola


Per aquesta practica he hagut de modificar una mica el meu struct de datos.h
per tal de poder guardar el temporal de les operacions, per aixo tinc el char *place.
Tambe he hagut de posar les funcions que tenia a datos.c al parser.y ja que necesitaba treballar per crear
els temporals i la sortida en codi 3AC directament desde el parser.y.

Per la resta no he tingut massa complicació, he anat guardant les coses a la meva matriu de codi 3AC conforme anaba fent operacions.

Considero que el codi que dona la practica 2 al enunciat es mes que suficient per testejar el programa. 
No he pogut implementar el cambi de signe, els comentaris de multiple linea ni les taules.

