/*SELECT * FROM pf_super.ventas;*/
/*
insert 
	into 
		ventas(idcliente)
	Values(clientes.idClientes)
where 
	clientes.NIT = '283192-2';*/
/*
IF NOT EXISTS(SELECT 1 FROM ventas WHERE clientes.NIT = '145300')
    INSERT INTO ventas(idcliente)
    VALUES(clientes.idclientes)*/

/*SELECT * FROM pf_super.ventas;

SELECT ventas.idcliente, clientes.NIT
FROM ventas
INNER JOIN clientes ON ventas.idcliente = clientes.idClientes
where idcliente Like 2;

/*inner join clientes on ventas.idcliente= cliente.idclientes;

/*buscar idcliente por el nit e insertar el id cliente en la tabla 

select * from clientes
where NIT = '283192-2';*/

/*insert into ventas(idcliente)Values(select idClientes from clientes ventas where ventas.idcliente= clientes.idClientes)
*/
/*insert into ventas(idcliente) select idClientes from clientes where clientes.NIT='283192-2'*/
/*
IF NOT EXISTS ( SELECT 1 FROM clientes WHERE clientes.NIT = '2')
BEGIN
    INSERT INTO Users (FirstName, LastName) VALUES ('John', 'Smith')
END
/*SELECT TOP 1 * FROM clientes WHERE idclientes = 2;*/
/*
WHERE [NOT] EXISTS 
( SELECT 1 FROM MyTable WHERE ... )*/

select idClientes,
case
	when idClientes = 5 then 'no user'
    end as se
    from clientes
    where clientes.NIT='5';
    
INSERT INTO ventas(nofactura,serie,fechafactura,idcliente,idempleado,fechaingreso)VALUES('1','A',NOW(),(select idClientes from clientes where clientes.NIT='5'), '2',NOW());
