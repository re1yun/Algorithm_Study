SELECT COUNT(*) AS USERS 
FROM USER_INFO
WHERE JOINED LIKE '%2021%'
AND AGE IS NOT NULL
AND AGE < 30
AND AGE > 19