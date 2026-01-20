import zstandard as zstd
import json
import zipfile
import os
import time

def stream_reddit_data(zip_path, output_file, target_count=1000000):
    """
    Stream Reddit data from compressed .zst file inside a zip archive.
    Extracts only id, created_utc, score fields.
    """
    
    print("=" * 60)
    print("  Reddit Dataset Streamer - 1M Posts Extraction")
    print("=" * 60)
    print()
    
    start_time = time.time()
    
    # Open the zip file
    print(f"Opening zip file: {zip_path}")
    
    with zipfile.ZipFile(zip_path, 'r') as zf:
        # List files in zip
        file_list = zf.namelist()
        print(f"Files in archive: {file_list}")
        
        # Find the .zst file
        zst_file = None
        for f in file_list:
            if f.endswith('.zst'):
                zst_file = f
                break
        
        if zst_file is None:
            print("Error: No .zst file found in archive!")
            return
        
        print(f"Processing: {zst_file}")
        print(f"Target: {target_count:,} posts")
        print()
        
        # Open and decompress
        with zf.open(zst_file) as compressed:
            dctx = zstd.ZstdDecompressor()
            
            with open(output_file, 'w', encoding='utf-8') as out:
                count = 0
                errors = 0
                
                # Stream decompression
                with dctx.stream_reader(compressed) as reader:
                    buffer = b''
                    chunk_size = 64 * 1024  # 64KB chunks
                    
                    while count < target_count:
                        chunk = reader.read(chunk_size)
                        if not chunk:
                            break
                        
                        buffer += chunk
                        lines = buffer.split(b'\n')
                        buffer = lines[-1]  # Keep incomplete line
                        
                        for line in lines[:-1]:
                            if not line.strip():
                                continue
                            
                            try:
                                data = json.loads(line.decode('utf-8'))
                                
                                # Extract only needed fields
                                post = {
                                    'id': data.get('id', ''),
                                    'created_utc': data.get('created_utc', 0),
                                    'score': data.get('score', 0)
                                }
                                
                                if post['id']:
                                    out.write(json.dumps(post) + '\n')
                                    count += 1
                                    
                                    # Progress indicator
                                    if count % 100000 == 0:
                                        elapsed = time.time() - start_time
                                        rate = count / elapsed
                                        remaining = (target_count - count) / rate
                                        print(f"  Processed: {count:,} posts ({count*100//target_count}%) - "
                                              f"Rate: {rate:.0f} posts/sec - "
                                              f"ETA: {remaining:.0f} sec")
                                    
                                    if count >= target_count:
                                        break
                                        
                            except (json.JSONDecodeError, UnicodeDecodeError) as e:
                                errors += 1
                                continue
    
    elapsed = time.time() - start_time
    
    print()
    print("=" * 60)
    print(f"  Extraction Complete!")
    print("=" * 60)
    print(f"  Total posts extracted: {count:,}")
    print(f"  Errors skipped: {errors:,}")
    print(f"  Time taken: {elapsed:.2f} seconds")
    print(f"  Output file: {output_file}")
    
    # Get file size
    file_size = os.path.getsize(output_file)
    print(f"  Output file size: {file_size / (1024*1024):.2f} MB")
    print("=" * 60)

if __name__ == "__main__":
    # Configuration
    ZIP_PATH = r"C:\Users\admin\Downloads\archive.zip"  # Update this path
    OUTPUT_FILE = "reddit_1m_sample.json"
    TARGET_COUNT = 1000000  # 1 Million posts
    
    stream_reddit_data(ZIP_PATH, OUTPUT_FILE, TARGET_COUNT)