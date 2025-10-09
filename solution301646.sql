-- https://school.programmers.co.kr/learn/courses/30/lessons/301646
-- 코드를 작성해주세요
SELECT COUNT(GENOTYPE) AS "COUNT"
FROM ECOLI_DATA
WHERE (GENOTYPE & 2) = 0 AND ((GENOTYPE & 1) > 0 OR (GENOTYPE & 4) > 0)
