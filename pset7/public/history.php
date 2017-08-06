<?php
 // configuration
    require("../includes/config.php"); 

    $rows=CS50::query("SELECT * FROM history WHERE user_id={$_SESSION["id"]}");
 
    $positions = [];
    foreach ($rows as $row)
    {

            $positions[] = [
                "Transaction" => $row["Transaction"],
                "Time" => $row["Time"],
                "Stock" => $row["Stock"],
                "Shares" => $row["Shares"],
                "Price" => $row["Price"],
            ];
    }
    

    // render portfolio
    render("history_log.php",["positions" => $positions, "title" => "History"]);

?>
