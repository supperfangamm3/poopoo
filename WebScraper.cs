using System;
using System.Net;
using HtmlAgilityPack;

class WebScraper
{
    public static void Main()
    {
        string url = "https://www.google.com";

        using (WebClient client = new WebClient())
        {
            string html = client.DownloadString(url);

            HtmlDocument doc = new HtmlDocument();

            doc.LoadHtml(html);

            var links = doc.DocumentNode.SelectNodes("//a[@href]");

            foreach (var link in links)
            {
                Console.WriteLine(link.Attributes["href"].Value);
            }
        }
    }
}
