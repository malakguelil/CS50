SELECT name FROM people
WHERE id = (SELECT * person_id  WHERE movie_id = (SELECT * movies WHERE year = 2004))
ORDER BY birth;
