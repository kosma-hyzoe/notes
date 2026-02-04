# Select Star


## Basics
* `SELECT * FROM "executions" LIMIT 3`, ciapki not required
* `SELECT 50 + 2, 51 * 2`
* `(LIKE '%-foobar200_ OR "year" = 2020' OR "year" < 2012);`
* `ROUND(AVG("rating"), 2) AS "average rating"`;
* `SUM("votes")`
* `SELECT COUNT(*) FROM`, `COUNT(DISTINCT "translator")`
* `JOIN "migrations" ON "migrations"."id" = "sea_lions"."id";`
  * inner - remove non-matching
  * outer - LEFT, RIGHT, `FULL JOIN`
  * `NATURAL JOIN` - "auto-finds" the primary key, skips `ON`
* `SELECT "name" FROM "authors" \nINTERSECT\n SELECT "name" FROM "translators";`
* `UNION`, `EXCEPT`
* `SELECT "author" AS "profession", "name" FROM "authors";`
```
SELECT "book_id", AVG("rating") AS "average rating"
FROM "ratings"
GROUP BY "book_id"
HAVING "average rating" > 4.0; # uses different conditions on rows and groups
```

## Sqlite3 specific
* `.mode table`

## Design
* CHECK
* DEFAULT
* NOT NULL, UNIQUE
* DROP TABLE, `ALTER TABLE "swipes" RENAME COLUMN "ttpe" TO "type";`
* TEXT, NUMERIC, INTEGER, REAL, BLOB
```
$ sqlite3 db.db
sqlite> .read schema.sql
sqlite> .schema "books"
```

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    email VARCHAR(255) NOT NULL UNIQUE,
    age INT CHECK (age >= 0),
    gender ENUM('Male', 'Female', 'Other'),
    registered_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    last_login TIMESTAMP NULL,
    role_id INT NOT NULL,
    FOREIGN KEY (role_id) REFERENCES roles(id),
    INDEX idx_email (email)
);
```
