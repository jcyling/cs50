SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name IN ("Johnny Depp", 'Helena Bonham Carter')
GROUP BY stars.movie_id
HAVING COUNT(distinct person_id) = 2;