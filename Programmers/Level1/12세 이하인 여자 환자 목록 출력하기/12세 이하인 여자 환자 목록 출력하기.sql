SELECT PT_NAME, PT_NO, GEND_CD, AGE, 
    CASE WHEN ISNULL(TLNO) THEN 'NONE' ELSE TLNO END AS TLNO
FROM PATIENT
WHERE AGE < 13 AND GEND_CD LIKE 'W'
ORDER BY AGE DESC, PT_NAME ASC