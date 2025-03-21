<?php
$filename = "sample2.txt";

if (!file_exists($filename)) {
    die("File not found!");
}

$file = fopen($filename, "r");

// Read the file data into an array
$items = [];
while (($line = fgets($file)) !== false) {
    $data = explode(",", trim($line)); // Assuming CSV format
    if (count($data) == 4) {
        $items[] = [
            "code" => $data[0],
            "name" => $data[1],
            "units" => (int)$data[2],
            "rate" => (float)$data[3],
        ];
    }
}

// Close the file
fclose($file);

// Display data in tabular format
echo "<table border='1' cellpadding='5' cellspacing='0'>";
echo "<tr><th>Item Code</th><th>Item Name</th><th>Units Sold</th><th>Rate</th><th>Total</th></tr>";

foreach ($items as $item) {
    $total = $item["units"] * $item["rate"];
    echo "<tr>
        <td>{$item['code']}</td>
        <td>{$item['name']}</td>
        <td>{$item['units']}</td>
        <td>{$item['rate']}</td>
        <td>{$total}</td>
    </tr>";
}

echo "</table>";
?>
