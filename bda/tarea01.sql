-- Mauro Rogelio Galindo Ibarra
-- Tarea 01


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
