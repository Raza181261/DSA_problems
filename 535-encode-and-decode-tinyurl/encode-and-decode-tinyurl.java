public class Codec {

      
      HashMap<String, String>mp = new HashMap<>();


    // Encodes a URL to a shortened URL.
    String encode(String longUrl) {
        StringBuilder sb = new StringBuilder();
        sb.append((char)(Math.floor(Math.random()*100)));
        while(mp.containsKey(sb.toString())) {
        sb.append((char)(Math.floor(Math.random()*100)));
        }
        mp.put(sb.toString(), longUrl);
        return sb.toString();
        
    }

    // Decodes a shortened URL to its original URL.
    String decode(String shortUrl) {
        return mp.get(shortUrl);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));