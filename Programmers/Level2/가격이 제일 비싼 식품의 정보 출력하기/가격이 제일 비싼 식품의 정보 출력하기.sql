SELECT FP.PRODUCT_ID, FP.PRODUCT_NAME, FP.PRODUCT_CD, FP.CATEGORY, FP.PRICE
FROM FOOD_PRODUCT AS FP,
(SELECT MAX(PRICE) AS PRICE FROM FOOD_PRODUCT) AS PR
WHERE FP.PRICE = PR.PRICE