<?php
    session_start();
    include_once "config.php";
    $userid = mysqli_real_escape_string($conn, $_POST['userid']);
    if(!empty($userid) && !empty($pass)){
        $sql = mysqli_query($conn, "SELECT * FROM members WHERE userid = '{$userid}'");
        if(mysqli_num_rows($sql) > 0){
            $row = mysqli_fetch_assoc($sql);
            if($pass === $row['pass']){
                $status = "Active now";
                $sql2 = mysqli_query($conn, "UPDATE members SET status = '{$status}' WHERE id = {$row['id']}");
                if($sql2){
                    $_SESSION['unique_id'] = $row['unique_id'];
                    $sql3 = mysqli_query($conn, "INSERT INTO messages (outgoing_msg_id, msg, notice)
                                                    VALUES ({$row['unique_id']}, '..', 2)") or die();
                    echo "success";
                } else{
                    echo "Something went wrong. Please try again!";
                }
            } else{
                echo " Password is Incorrect!";
            }
        }else{
            echo "$userid - This id not Exist!";
        }
    }else{
        echo "All input fields are required!";
    }
?>
