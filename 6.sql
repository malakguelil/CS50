SELECT AVG(rating)
FROM ratings 
WHERE movies_id = (SELECT id FROM  movies WHERE year = 2012);
