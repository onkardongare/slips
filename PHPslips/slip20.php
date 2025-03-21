<?php
    $filename = 'sample.txt';

    echo "Type : " . filetype($filename) . "<br>";
    echo "Accessed : " . date("Y-m-d H:i:s" ,  fileatime($filename)) . "<br>";
    echo "Filesize : " . filesize($filename) . "<br>";
    unlink($filename);
    echo "File Deleted";
?>