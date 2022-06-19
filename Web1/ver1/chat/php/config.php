<?php
$conn = mysqli_connect(
  "localhost",
  "root",
  "496500",
  "chatapp"
);

  if(!$conn){
    echo "Database connection error".mysqli_connect_error();
  }
?>
