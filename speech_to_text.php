<?php
// Enable error reporting for debugging
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Required variables to connect with the local database
$servername = "localhost";
$username = "";
$password = ""; 
$db = "Robot";

// Create connection
$conn = new mysqli($servername, $username, $password, $db);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Initialize response variables
$command = "Unknown";

// Handle POST request
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['transcript'])) {
        $transcript = mysqli_real_escape_string($conn, $_POST['transcript']);

        // Determine command based on transcript
        if (strpos(strtolower($transcript), 'open') !== false) {
            $command = '1';
        } elseif (strpos(strtolower($transcript), 'close') !== false) {
            $command = '0';
        } else {
            $command = 'Unknown';
        }

        // Insert command into database if valid
        if ($command !== 'Unknown') {
            $stmt = $conn->prepare("INSERT INTO speech_to_text_data (transcript, command) VALUES (?, ?)");
            $stmt->bind_param("ss", $transcript, $command);

            if ($stmt->execute()) {
                // Success message
                echo "Record inserted successfully. Command: $command";
            } else {
                // Error message
                echo "Error: " . $stmt->error;
            }

            $stmt->close();
        } else {
            echo "Unknown command, not saved.";
        }
    }
}

// Fetch and display the latest command
$result = $conn->query("SELECT command FROM speech_to_text_data ORDER BY id DESC LIMIT 1");
if ($result && $row = $result->fetch_assoc()) {
    $latestCommand = $row['command'];
} else {
    $latestCommand = "No command found.";
}

// Close the connection
$conn->close();

// Output the latest command as plain text
echo $latestCommand;
?>
