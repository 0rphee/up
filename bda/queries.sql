-- ingresos por customer
SELECT customerNumber,  SUM(quantityOrdered * priceEach) AS Tot
FROM orders, orderdetails
WHERE
    orders.orderNumber = orderdetails.orderNumber
    AND orders.status IN ('Shipped', 'Resolved')
    AND YEAR(orders.orderDate) = 2003
GROUP BY customerNumber
ORDER BY customerNumber;


-- ingresos por año
SELECT YEAR(orders.orderDate),  SUM(quantityOrdered * priceEach) AS Tot
FROM orders, orderdetails
WHERE
    orders.orderNumber = orderdetails.orderNumber
    AND orders.status IN ('Shipped', 'Resolved')
--     AND YEAR(orders.orderDate) = 2003
GROUP BY YEAR(orders.orderDate);

-- DISTINCT para obtener únicos

-- Ventas por año por país
SELECT YEAR(orders.orderDate) AS _Y_, offices.country, SUM(quantityOrdered * priceEach) AS Tot
FROM orders, orderdetails, customers, employees, offices
WHERE
    orders.orderNumber = orderdetails.orderNumber
    AND orders.customerNumber = customers.customerNumber
    AND customers.salesRepEmployeeNumber = employees.employeeNumber
    AND employees.officeCode = offices.officeCode
    AND orders.status IN ('Shipped', 'Resolved')
GROUP BY _Y_, offices.country
ORDER BY _Y_, offices.country;


-- Tarea BDA. Obtener por país, las categorías más vendidas por unidades vendidades. Manteniendo shipped y resolved

SELECT offices.country, productlines.productLine, SUM(quantityOrdered) AS TotUnidadesVendidas
FROM orders, orderdetails, customers, employees, offices, products, productlines
WHERE
    orders.orderNumber = orderdetails.orderNumber
    AND orders.customerNumber = customers.customerNumber
    AND customers.salesRepEmployeeNumber = employees.employeeNumber
    AND employees.officeCode = offices.officeCode
    AND products.productCode = orderdetails.productCode
    AND products.productLine = productlines.productLine
    
    AND orders.status IN ('Shipped', 'Resolved')
GROUP BY offices.country, productlines.productLine
ORDER BY offices.country, TotUnidadesVendidas DESC;
