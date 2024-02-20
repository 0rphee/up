/*

MAURO ROGELIO GALINDO IBARRA
0250061

*/

/*
011.- Determine cuál de los años 2003 o 2004 facturó menos.
*/
SELECT YEAR(orderDate) AS Y, SUM(OD.quantityOrdered * OD.priceEach) AS cost
FROM orders, orderdetails AS OD
WHERE
    status = "Shipped"
    AND
    (
        YEAR(orderDate) = 2003
        OR
        YEAR(orderDate) = 2004
    )
GROUP BY Y
ORDER BY cost;

/*
año que facturó menos 2003

012.- Para el año que facturó menos según (011), indiqué qué mes facturó menos.
*/


SELECT MONTH(orderDate) AS Y, SUM(OD.quantityOrdered * OD.priceEach) AS cost
FROM orders, orderdetails AS OD
WHERE
    status = "Shipped"
    AND
    (
        YEAR(orderDate) = 2003
    )
GROUP BY Y
ORDER BY cost;

/*
en año que facturó menos, el mes que facturó menos: 2 - feb

013.- Para el año y mes de peor desempeño según (011 y 012), indique qué producto se vendió menos en dinero.

*/

SELECT productlines.productLine, SUM(OD.quantityOrdered * OD.priceEach) AS cost
FROM productlines, products, orders, orderdetails AS OD
WHERE
    status = "Shipped"
    AND
    YEAR(orderDate) = 2003
    AND
    MONTH(orderDate) = 2
    AND
    products.productCode = OD.productCode
    AND
    productlines.productLine = products.productLine
GROUP BY productlines.productLine
ORDER BY cost;

/*
-- producto que vendió menos en dinero Trains

-- 014.- Para el año y mes de mejor desempeño según (011 y 012), indique qué línea de producto se vendió más en unidades vendidas.
*/

SELECT MONTH(orderDate) AS Y, SUM(OD.quantityOrdered * OD.priceEach) AS cost
FROM orders, orderdetails AS OD
WHERE
    status = "Shipped"
    AND
    (
        YEAR(orderDate) = 2004
    )
GROUP BY Y
ORDER BY cost DESC;

/*
mes y año que facturan más
2004
11
*/

SELECT productlines.productLine, SUM(OD.quantityOrdered) AS units
FROM productlines, products, orders, orderdetails AS OD
WHERE
    status = "Shipped"
    AND
    YEAR(orderDate) = 2004
    AND
    MONTH(orderDate) = 11
    AND
    products.productCode = OD.productCode
    AND
    productlines.productLine = products.productLine
GROUP BY productlines.productLine
ORDER BY units DESC;

/*
Classic Cars - 1103042

015.- Para el año que facturó menos según (011), indique el promedio de lo facturado de los 12 meses.
*/

SELECT YEAR(orderDate) AS Y, AVG(OD.quantityOrdered * OD.priceEach) AS cost
FROM orders, orderdetails AS OD
WHERE
    status = "Shipped"
    AND
    YEAR(orderDate) = 2003

GROUP BY Y
ORDER BY cost;

/*
2003 - 3205.671098130297
*/

