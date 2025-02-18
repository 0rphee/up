//
//  ContentView.swift
//  linktree
//
//  Created by roger on 14/02/25.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView {
            VStack(spacing: 30) {
                Text("Mauro Rogelio Galindo Ibarra").bold().font(.title)

                Image("yo")
                    .resizable()
                    .scaledToFit()
                    .frame(width: 120, height: 120)
                    .clipShape(Circle())
                    .padding()

                customButton(
                    text: "Instagram",
                    urlStr: "https://www.instagram.com/rochaaaaaaaaaaaaaaa",
                    bgcolor: .pink
                ).frame(maxWidth: .infinity)

                customButton(
                    text: "GitHub", urlStr: "https://github.com/0rphee",
                    bgcolor: .black)
                NavigationLink(
                    destination: Sobre(),
                    label: {
                        Text("Sobre mí").padding()
                    }
                ).buttonStyle(.borderedProminent).tint(.blue)
                
                 NavigationLink(
                    destination: Dato(),
                    label: {
                        Text("Dato curioso").padding()
                    }
                ).buttonStyle(.borderedProminent).tint(.blue)
                
            }
        }
        .padding()
        .navigationTitle("LinkTree Rogelio")
    }
}

#Preview {
    ContentView()
}

func customButton(text: String, urlStr: String, bgcolor: Color) -> some View {
    Link(destination: URL(string: urlStr)!, label: { Text(text).padding() })
        .buttonStyle(.borderedProminent).tint(bgcolor)
}
