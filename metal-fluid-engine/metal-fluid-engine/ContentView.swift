//
//  ContentView.swift
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/28.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack {
            MTLView()
        }
        .ignoresSafeArea(.all)
    }
}

#Preview {
    ContentView()
}
