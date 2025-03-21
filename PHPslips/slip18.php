<?php
// PostgreSQL Database Connection
$conn = pg_connect("host=localhost port=5432 dbname=onkar user=postgres password=onkar");

// Check connection
if (!$conn) {
    die("Database connection failed!");
}

// SQL queries to create tables if not exists
$queries = [
    "CREATE TABLE IF NOT EXISTS Event (
        eno INT PRIMARY KEY,
        title VARCHAR(255),
        date DATE
    );",

    "CREATE TABLE IF NOT EXISTS Committee (
        cno INT PRIMARY KEY,
        name VARCHAR(255) UNIQUE,
        head VARCHAR(255),
        from_time TIME,
        to_time TIME,
        status VARCHAR(50) DEFAULT 'Pending'
    );",

    "CREATE TABLE IF NOT EXISTS Event_Committee (
        eno INT REFERENCES Event(eno),
        cno INT REFERENCES Committee(cno),
        PRIMARY KEY (eno, cno)
    );"
];

foreach ($queries as $query) {
    $result = pg_query($conn, $query);
}

// Insert dummy data (Committees first to avoid FK constraint error)
$insert_queries = [
    "INSERT INTO Committee (cno, name, head, from_time, to_time, status) VALUES 
        (1, 'Planning Committee', 'Alice', '09:00', '12:00', 'Pending');",
    
    "INSERT INTO Committee (cno, name, head, from_time, to_time, status) VALUES 
        (2, 'Logistics Committee', 'Bob', '10:00', '14:00', 'Pending');",

    "INSERT INTO Event (eno, title, date) VALUES (1, 'Hackathon', '2025-04-01');",
    
    "INSERT INTO Event (eno, title, date) VALUES (2, 'Tech Meetup', '2025-05-01');",
    
    "INSERT INTO Event_Committee (eno, cno) VALUES (1, 1);",
    
    "INSERT INTO Event_Committee (eno, cno) VALUES (2, 2);"
];

// Execute insert queries
foreach ($insert_queries as $query) {
    $result = pg_query($conn, $query);
    if (!$result) {
        echo "Error inserting data: " . pg_last_error($conn) . "<br>";
    }
}

echo "Tables created and dummy data inserted successfully!";

// Close connection
pg_close($conn);

?>