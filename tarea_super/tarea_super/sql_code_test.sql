SELECT * FROM pf_super.clientes;

select nombres, apellidos, NIT, telefono,correo_electronico,fechaingreso,\
CASE\
	WHEN genero = 109 THEN 'hombre'\
	WHEN genero = 102 then 'mujer'\
	ELSE 'ERROR'\
END AS genero\
from clientes;

select *,
CASE
	WHEN genero = 109 THEN 'hombre'
	WHEN genero = 102 then 'mujer'
	ELSE 'ERROR'
END AS Cgenero
from clientes;


SELECT empleados.nombres,empleados.apellidos,empleados.direccion,empleados.telefono,empleados.DPI,empleados.genero,empleados.fecha_nacimiento,puestos.puesto,empleados.fecha_inicio_labores,empleados.fechaingreso,\
CASE\
	WHEN empleados.genero = 109 THEN 'hombre'\
    WHEN empleados.genero = 102 then 'mujero'\
    ELSE 'error'\
END AS genero\
FROM empleados\
INNER JOIN puestos\
ON empleados.idPuesto=puestos.idpuesto;