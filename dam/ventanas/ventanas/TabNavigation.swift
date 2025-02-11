//
//  TabNavigation.swift
//  ventanas
//
//  Created by roger on 10/02/25.
//

import SwiftUI

struct TabNavigation: View {
    var body: some View {
        TabView {
            View2()
            .tabItem {
                    Label("Tab 1", systemImage: "globe")
                }

            View3()
                .tabItem {
                    Label("Tab2 ", systemImage: "house")
                }
        }

    }
}

#Preview {
    TabNavigation()
}
