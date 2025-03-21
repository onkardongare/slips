<?php
    $big = $_GET['big_string'];
    $small = $_GET['small_string'];
    $operation = $_GET['operation'];
    $n = $_GET['n'] ?? 0;

    function startsWith($big, $small) {
        return strpos($big, $small) === 0;
    }

    function findPosition($big, $small) {
        $pos = strpos($big, $small);
        if($pos !== false){
            return $pos;
        }
        else{
            return 'not found';
        }
    }

    function compareFirstN($big, $small, $n) {
        return strncasecmp($big, $small, $n) == 0;
    }

    echo "<h3>Result: ";
    if ($operation == "starts_with") echo startsWith($big, $small) ? "Yes" : "No";
    else if ($operation == "position") echo findPosition($big, $small);
    else if ($operation == "compare") echo compareFirstN($big, $small, $n) ? "Match" : "No Match";
    else echo "Invalid selection!";
    echo "</h3>";
?>
        