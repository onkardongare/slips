<?php
$conn = pg_connect("host=localhost port=5432 dbname=onkar user=postgres password=onkar");


$queries = [
    "CREATE TABLE IF NOT EXISTS Owner (
        oname VARCHAR(255) PRIMARY KEY,
        address TEXT,
        phone VARCHAR(15)
    );",

    "CREATE TABLE IF NOT EXISTS Property (
        pno SERIAL PRIMARY KEY,
        description TEXT,
        area FLOAT,
        oname VARCHAR(255) REFERENCES Owner(oname)
    );"
];

foreach ($queries as $query) {
    $result = pg_query($conn, $query);
    if (!$result) {
        echo "Error creating table: " . pg_last_error($conn) . "<br>";
    }
}

// Insert dummy data (Owner first to avoid FK constraint errors)
$insert_queries = [
    "INSERT INTO Owner (oname, address, phone) VALUES 
        ('Alice', '123 Main St, Delhi', '9876543210') 
    ON CONFLICT (oname) DO NOTHING;",

    "INSERT INTO Owner (oname, address, phone) VALUES 
        ('Bob', '456 Market Rd, Mumbai', '8765432109') 
    ON CONFLICT (oname) DO NOTHING;",

    "INSERT INTO Property (description, area, oname) VALUES 
        ('3BHK Apartment', 1200.5, 'Alice') 
    ON CONFLICT DO NOTHING;",

    "INSERT INTO Property (description, area, oname) VALUES 
        ('2BHK Flat', 900.0, 'Alice') 
    ON CONFLICT DO NOTHING;",

    "INSERT INTO Property (description, area, oname) VALUES 
        ('Commercial Space', 2000.0, 'Bob') 
    ON CONFLICT DO NOTHING;"
];

// Execute insert queries
foreach ($insert_queries as $query) {
    $result = pg_query($conn, $query);
    if (!$result) {
        echo "Error inserting data: " . pg_last_error($conn) . "<br>";
    }
}

echo "Tables created and dummy data inserted successfully!";


$owner_name = 'Alice';

$query = "SELECT * FROM Property WHERE oname = 'Alice'";
$result = pg_query($conn, $query);
    if ($result) {
            while ($row = pg_fetch_assoc($result)) {
                echo implode(", ", $row) . "<br>";
            }
    } else {
        echo "Error: " . pg_last_error($conn);
    }
// Close connection
pg_close($conn);
?>
