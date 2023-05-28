_# Proyecto final - ticketmaster2
---
##### Colaboradores:
- Braulio Chamerry 
- David Emmanuel Santana 
- Renata Flores
---
### Información General
- El presente proyecto recrea a pequeña escala un sistema de venta de boletos similar al funcionamiento de la empresa Ticketmaster. 
---
### Manual de Usuario
- Al inicio, el programa muestra un menú con 2 opciones disponibles: Cliente y Administrador.
- Este es el menú principal del programa, elige una de las opciones al presionar 1 o 2, o bien salir del programa presionando la tecla -. <br>
- Al escoger una de las opciones: <br>
    - __Cliente:__ <br>
    A continuación, se desplegará un nuevo menú con 3 opciones: Iniciar Sesión, Crear Usuario y Salir. <br>
    __NOTA:__ Si eres nuevo ingresa a la opción "Crear Usuario" para poder asignar un ID. 
      - __Iniciar Sesión:__  <br>
      Inicia Sesión con tu cuenta Ticketmaster2 <br>
      **Entrada**: *int y contraseña* (Tu ID y contraseña). <br>
      **Salida**: *"Sesión Iniciada" + Bono por iniciar sesión*  <br>
      __NOTA:__ _En caso de no tener un ID se muestra en pantalla un mensaje de error y se volverá a mostrar
      el menú de clientes._ <br>
      _Solo 3 intentos para escribir la contraseña correctamente o se mostrará un mensaje en pantalla._ <br>
      Seguido de esto se desplegará un nuevo menú con 4 opciones: Inventario, Comprar, Chambear y Salir. <br>
        - __Inventario:__ <br>
        **Entrada**: *int* (ID del boleto a usar o 0) <br>
        **Salida**: *Lista de boletos comprados* <br>
        _En caso de no contar con algún boleto, se manda un mensaje y se tiene que presionar ENTER para regresar._
        - __Comprar:__ <br> 
        **Entrada**: *int* (ID de boleto a comprar o 0 para cancelar) <br>
        Si quieres que el boleto sea VIP presiona 1, si no presiona 0. <br>
        **Salida**: *Lista de Eventos* <br>
        __NOTA:__ En caso de no contar con el dinero suficiente, se mencionará cual es la cantidad de dinero faltante
        y se muestra el menú de tienda. <br>
        - __Chambear:__ <br>
        **Entrada**: *N/A* <br>
        **Salida**: *Has obtenido +"dinero"* <br>
        - __Salir:__ <br>
        Regresa al Menú del Cliente. <br>
        **Entrada**: *N/A* <br>
        **Salida**: *Menú del Cliente* <br>
      - __Crear Usuario:__ <br>
      Escribe una contraseña para iniciar sesión como usuario. <br>
      **Entrada**: *Contraseña (8 a 30 caracteres)* <br>
      **Salida**: *Tu contraseña, ID y un bono de dinero.* <br>
      __NOTA:__  _Nuevamente se mostrará el menú de cliente donde ya se puede iniciar sesión con tu ID y contraseña._ <br>
      - __Salir:__ <br>
      Regresa al Menú Principal. <br>
      **Entrada**: *N/A* <br>
      **Salida**: *Menú Principal* <br>
    - __Administrador:__ <br>
    **Entrada**: *Contraseña* (blockbuster123) <br>
    **Salida**: *Menú del Administrador* <br>
      - __Crear Evento:__ <br>
      Crea un nuevo evento. <br>
      **Entrada**: *Detalles del Evento* (nombre, lugar, año, mes, día, hora, minuto, artista, dirección, precio) <br>
      **Salida**: *N/A* <br>
      - __Estadísticas de ventas:__ <br>
      Muestra las ganancias generadas por la venta de boletos. <br>
      **Entrada**: *float* (costoTotal = costo administrativo) <br>
      **Salida**: *Ingresos Totales, Ganancias, Porcentaje de Ganancias.* <br>
      - __Información de Usuarios:__ <br>
      **Entrada**: *N/A* <br>
      **Salida**: *Lista de información de clientes* (ID, Cantidad de boletos, Saldo actual) <br>
      - __Cambiar Contraseña Maestra:__ <br>
      **Entrada**: *Contraseña* (8 a 30 caracteres) <br>
      **Salida**: *Contraseña* (Oculta) <br>
      - __Salir__ <br>
      Regresa al Menú Principal. <br>
      **Entrada**: *N/A* <br>
      **Salida**: *Menú Principal* <br>
    - __Salir:__ <br>
    Sale del programa. <br>
    **Entrada**: *N/A* <br>
    **Salida**: *"Guardando datos y limpiando la memoria..."* <br>
    
      
      
        
  
