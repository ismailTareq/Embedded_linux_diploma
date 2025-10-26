use regex::Regex;

#[derive(Debug)]
struct LogEntry {
    timestamp: String,
    category: String,
    endpoint: String,
    id: String,
}

fn main() {
    let server_logs = vec![
        "[2025-06-15 14:32:10] INFO: User 127.0.0.1 requested /api/orders/12345",
        "[2025-06-15 14:33:02] ERROR: Failed to fetch /api/users/9876",
        "[2025-06-15 14:34:55] DEBUG: User 10.0.0.1 requested /api/products/999",
        "!!!!",
        "[2025-06-15 14:35:01] INFO: User 192.168.1.5 requested /api/orders/54321",
        "[2025-06-15 14:35:45] ERROR: Failed to fetch /api/products/4567",
        "!!!!",
        "[2025-06-15 14:36:12] WARN: User 10.0.0.99 requested /api/users/101",
        "[2025-06-15 14:37:09] INFO: User 127.0.0.1 requested /api/categories/88",
        "[2025-06-15 14:37:59] WARN: Malformed URL detected",
        "[2025-06-15 14:38:42] INFO: User 172.16.0.10 requested /api/orders/11111",
        "[2025-06-15 14:39:00] DEBUG: Skipping health check ping",
        "[2025-06-15 14:40:20] ERROR: Failed to fetch /api/orders/00000",
        "!!!!",
    ];

    let re = Regex::new(
        r"\[(?<timestamp>\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2})\]\s(?<category>INFO|ERROR|DEBUG|WARN):\s.+/api/(?<endpoint>\w+)/(?<id>\d+)",
    )
    .unwrap();

    let entries: Vec<_> = server_logs
        .into_iter()
        .filter_map(|log| re.captures(log))
        .map(|capture| LogEntry {
            timestamp: capture["timestamp"].to_string(),
            category: capture["category"].to_string(),
            endpoint: capture["endpoint"].to_string(),
            id: capture["id"].to_string(),
        })
        .collect();

    println!("{entries:#?}");
}

