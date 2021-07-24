SELECT DISTINCT(name) FROM people WHERE name IS NOT "Kevin Bacon" AND people.id IN
(SELECT stars.person_id from stars where stars.movie_id IN
    (SELECT stars.movie_id FROM stars WHERE stars.person_id IN
        (SELECT people.id FROM people WHERE people.name = "Kevin Bacon" AND people.birth = "1958"
        )
    )
)
ORDER BY name;