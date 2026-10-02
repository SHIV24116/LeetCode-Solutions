# Write your MySQL query statement below
SELECT ROUND(AVG(d.order_date=d.customer_pref_delivery_date)*100,2) AS immediate_percentage
FROM Delivery d
WHERE d.order_date=(
    SELECT MIN(order_date)
    FROM Delivery
    WHERE customer_id=d.customer_id
);