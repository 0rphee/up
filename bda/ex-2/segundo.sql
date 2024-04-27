SELECT MATCH (productDescription) AGAINST ("wood metal" IN NATURAL LANGUAGE MODE) AS Score, 
products.productCode, products.productName, SUM(orderdetails.quantityOrdered) AS UnidadesVendidasEuropa

FROM products, orderdetails, orders, customers, employees, offices
WHERE
 products.productCode = orderdetails.productCode
 AND
 orderdetails.orderNumber = orders.orderNumber
 AND
 orders.customerNumber = customers.customerNumber
 AND
 customers.salesRepEmployeeNumber = employees.employeeNumber
 AND
 employees.officeCode = offices.officeCode
 AND

 (
     offices.country = "UK"
     OR
     offices.country = "France"
 )
 AND
 YEAR(orders.orderDate) = 2004

GROUP BY products.productCode
ORDER BY Score DESC;
